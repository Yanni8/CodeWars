#include <vector>
#include <string>
#include <iostream>
#include <map>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};


std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr){
    const std::map<std::string, std::string> oposite = {{"NORTH", "SOUTH"}, {"SOUTH", "NORTH"}, {"WEST", "EAST"}, {"EAST", "WEST"}};
    bool canBeReduced = true;
    while (canBeReduced)
    {
        canBeReduced = false;
        size_t arraySize = arr.size();
        for (size_t i = 1; i < arraySize; i++)
        {   
            std::cout << arraySize << " " << i << " " << arr.size() << std::endl;
            if(oposite.at(arr.at(i-1)) == arr.at(i)){
                canBeReduced = true;
                arr.erase(arr.begin()+i);
                arr.erase(arr.begin()+i-1);
                arraySize -= 2;
            }
        }
        
    }
    

    return arr;
}



int main(int argc, char const *argv[])
{
    std::vector<std::string> directions = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    
    for( auto &direction : DirReduction::dirReduc(directions)){
        std::cout << direction << " ";
    } 
    std::cout << " Expected Result {'WEST'}" << std::endl;
    return 0;
}
