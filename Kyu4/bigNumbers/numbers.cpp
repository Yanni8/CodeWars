#include <iostream>
#include <string>
#include <algorithm> 
#include <regex>

std::string addString(std::string& s1, std::string& s2){
    
    if(s1.size() > s2.size()){
        return addString(s2,s1);
    }
    std::string result = "";
    std::reverse(s1.begin(), s1.end()); std::reverse(s2.begin(), s2.end());
    unsigned int overflow = 0, n1 = 0, n2 = 0;

    for (size_t ptr = 0; ptr < s1.size(); ptr++)
    {
        overflow += (s1.at(ptr) - '0') + (s2.at(ptr) - '0');
        result += std::to_string(overflow % 10);
        overflow /= 10;
    }
    size_t ptr = s1.size();
    while (overflow || ptr < s2.size())
    {
        
        if (ptr < s2.size())
        {
            overflow += s2.at(ptr) - '0';
        }
        result += std::to_string(overflow%10);
        overflow /= 10;
        ptr++;
    }
    
    std::reverse(result.begin(), result.end());

    return result;
}


std::string multiply(std::string a, std::string b) {
    
    std::string result = "0", byteResult;
    std::reverse(a.begin(), a.end()); std::reverse(b.begin(), b.end());
    unsigned int a_pow = 0, b_pow = 0;
    for (char& c_a : a)
    {
        b_pow = 0;
        for (char& c_b : b)
        {
            byteResult = std::to_string((c_a - '0') * (c_b - '0')) + std::string(a_pow + b_pow, '0'); 
            
            result = addString(result, byteResult);
            b_pow++;
        }
        a_pow++;   
    }

    result = std::regex_replace(result, std::regex("^0*"), "");
    if (result.empty())
    {
        return "0";
    }
    
    return result;
    
}

int main(int argc, char * argv[]){
    std::cout << multiply("30", "0") << std::endl;
} 