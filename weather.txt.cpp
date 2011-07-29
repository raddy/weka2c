#include <iostream>

using namespace std;

string classify(string outlook, string windy, double humidity){

  if (outlook = sunny){
    if (humidity <= 75){
      return "yes";
    }
    else{
      return "no";
    }
  }
  else{
    return "yes";
  }
  else{
    if (windy = TRUE){
      return "no";
    }
    else{
      return "yes";
    }
  }

}