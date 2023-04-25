#include<iostream>

#define LOG(x) std::cout << (x) << std::endl

#include <string>
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        std::string reverseStr = std::to_string(x);
        std::reverse(reverseStr.begin(), reverseStr.end());
        try{
            return std::stoi(reverseStr) *  (x < 0 ? -1 : 1);
        } catch(std::out_of_range e){
            return 0;
        }
    }
};