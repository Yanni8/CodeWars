#include <iostream>

typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n);
};
ull SumFct::perimeter(int n){
    ull fib = 1, lastFib = 1, sum = 2, tmp;
    for (int i = 0; i < n-1; i++)
    {
        tmp = fib;
        fib += lastFib;
        lastFib = tmp;
        sum += fib;
    }

    return sum * 4;
}

/*
    URL:  https://www.codewars.com/kata/559a28007caad2ac4e000083
*/
int main(int argc, char * argv[]){
    std::cout << SumFct::perimeter(5) << " Should be 80" << std::endl;
    std::cout << SumFct::perimeter(20) << " Should be 114624" << std::endl;
    std::cout << SumFct::perimeter(30) << " Should be 14098308" << std::endl;
}