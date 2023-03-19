#include <iostream>

const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,153, 370, 371, 407,1634, 8208, 9474,54748, 92727, 93084,548834,1741725, 4210818, 9800817, 9926315,24678050, 24678051, 88593477,146511208, 472335975, 534494836,912985153};


bool narcissistic( int value ){   
    for (int ptr = 32; ptr--;)
    {
        if (value == arr[ptr])
        {
            return true;
        }
        
    }
    return false;
}


/**
 * URL: https://www.codewars.com/kata/5287e858c6b5a9678200083c/
*/
int main(int argc, char* argv[]){
    if (argc == 2)
    {
        std::cout << (narcissistic(std::stoi(argv[1])) ? "is Narcissistic" : "is not Narcissistic" ) << std::endl;
    }   
    
}