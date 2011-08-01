#include <iostream>

using namespace std;

double classify(string outlook, string windy, double humidity){

  if((humidity>=85) && (outlook=="sunny"))
    return -1;
  if((outlook=="rainy") && (windy=="TRUE"))
    return -1;
  else
    return 1;

}