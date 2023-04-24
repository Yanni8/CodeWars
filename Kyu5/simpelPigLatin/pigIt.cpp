#include<iostream>

#define LOG(x) std::cout << (x) << std::endl

#include <string>
#include <sstream>
#include <regex>

std::string pig_it(std::string str)
{
    std::istringstream stream(str);
    std::string word, out;
    while (stream >> word)
    {
        if (std::regex_match(word,std::regex("^[^a-zA-Z]+$")))
        {
            out += word + " ";
            continue;
        }
        
        out +=  word.substr(1) + word.substr(0,1) + "ay ";
    }
    out.pop_back();

    return out;
}


int main(int argc, char * argv[]){
    if (argc == 2)
    {
        LOG(pig_it(argv[1]));
    }
    
}