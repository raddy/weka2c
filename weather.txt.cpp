#include <iostream>

using namespace std;

string classify(string outlook, string windy, double humidity){

  if (outlook == "sunny"){
    if (humidity <= 75){
      return "yes";
    }
    elseif (humidity > 75){
      return "no";
    }
  }
  elseif (outlook == "overcast"){
    return "yes";
  }
  elseif (outlook == "rainy"){
    if (windy == "TRUE"){
      return "no";
    }
    elseif (windy == "FALSE"){
      return "yes";
    }
  }

}