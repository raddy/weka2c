#include <iostream>

using namespace std;

double classify(string outlook, string windy, double humidity){

  if (outlook == "sunny"){
    if (humidity <= 75){
      return 1;
    }
    elseif (humidity > 75){
      return -1;
    }
  }
  elseif (outlook == "overcast"){
    return 1;
  }
  elseif (outlook == "rainy"){
    if (windy == "TRUE"){
      return -1;
    }
    elseif (windy == "FALSE"){
      return 1;
    }
  }

}