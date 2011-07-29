#include <iostream>

using namespace std;

double classify(string outlook, string windy, double humidity){

  if (outlook = sunny){
    if (humidity <= 75){
      return 1;
    }
    else{
      return -1;
    }
  }
  else{
    return 1;
  }
  else{
    if (windy = TRUE){
      return -1;
    }
    else{
      return 1;
    }
  }

}