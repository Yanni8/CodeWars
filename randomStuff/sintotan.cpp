#include <iostream>
#include <string>
#include <math.h>

/*
Calculates tan from a given sin
*/
int main(int argc, char * argv[]){
    if (argc != 2)
    {   
        std::cout << "Syntax " << argv[0] << " <Sin>" << std::endl;
        exit(-1);
    }

    double sin = std::stod(argv[1]);
    if(sin > 1 || sin < -1){
        std::cout << "Are you sure that you entered a valid sin (range -1 to +1) :)" << std::endl;
        exit(69);
    }
    double cos = std::sqrt(1 - std::pow(sin,2)), tan = sin/cos;
    if (isinf(tan))
    {
        std::cout << "This value isnt defined" << std::endl;
        exit(0);
    }
    
    std::cout << "Calculated tan: " << sin/cos << std::endl;
}