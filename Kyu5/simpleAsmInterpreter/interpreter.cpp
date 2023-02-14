#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
    return regs.at(name);
}

bool isNumeric(const std::string& s)
{   
    if(s.at(0) == '-'){
        return !s.empty() && s.substr(1).find_first_not_of("0123456789") == std::string::npos;
    }
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}


std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
    std::unordered_map<std::string, int> variables;

    for (size_t ptr = 0; ptr < program.size(); ptr++)
    {

        std::string line = program.at(ptr), decition = line.substr(0,3);
        if (decition == "mov")
        {
            int start = line.find(" ")+1, end  = line.rfind(" ")-1;
            std::string key = line.substr(start, start-end+1) , value = line.substr(line.rfind(" ")+1);
            if (isNumeric(value))
            {
                variables[key] = std::stoi(value);
            } else{
                int refValue = variables.at(value);
                variables[key] = refValue;
            }
            
        } else if (decition == "inc")
        {
            std::string key = line.substr(line.find(" ")+1);
            variables.at(key)++;
        } else if (decition == "dec")
        {
            std::string key = line.substr(line.find(" ")+1);

            variables.at(key)--;
        } else if (decition == "jnz")
        {
            int start = line.find(" ")+1, end  = line.rfind(" ")-1;
            std::string condition = line.substr(start, start-end+1) , value = line.substr(line.rfind(" ")+1);
            if ((condition == "0" || (!isNumeric(condition) && variables.at(condition) == 0))){
                continue;
            }

            if(isNumeric(value)){
                ptr += std::stoi(value);
            }else{
                ptr += variables.at(value);
            }
            ptr--;
        }
        
        
    }

    return variables;
}

/**
 * URL: https://www.codewars.com/kata/58e24788e24ddee28e000053
*/
int main(int argc, char * argv[]){
    std::vector<std::string> program{ "mov a 1","mov b 1","mov c 0","mov d 26","jnz c 2","jnz 1 5","mov c 7","inc d","dec c","jnz c -2","mov c a","inc a","dec b","jnz b -2","mov b c","dec d","jnz d -6","mov c 18","mov d 11","inc a","dec d","jnz d -2","dec c","jnz c -5" };
    std::unordered_map<std::string, int> results = assembler(program);
    std::cout << getReg(results, "a") << " Should be 318009" << std::endl;
}