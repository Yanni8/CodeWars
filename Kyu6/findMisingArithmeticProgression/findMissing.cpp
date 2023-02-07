#include <iostream>
#include <vector>


static long findMissing(std::vector<long> list){
  long div = list[1] - list[0], checkDiv = list[2] - list[1];
  
  if (div > checkDiv)
  {
    div = checkDiv;
  }

  long lastValue = -1;
  for (long value : list)
  {
    if (lastValue == -1)
    {
      lastValue = value;
      continue;
    }
    
    if (lastValue + div != value)
    {
      return lastValue + div;
    }
    lastValue = value;
  }
  return 0;
}

/*
URL: https://www.codewars.com/kata/52de553ebb55d1fca3000371/train/cpp
*/
int main(int argc, char * argv[]){

    std::cout << findMissing({2,5,11}) << std::endl;
}