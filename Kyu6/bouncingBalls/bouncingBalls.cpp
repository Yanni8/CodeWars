#include <iostream>

#define LOG(x) std::cout << (x) << std::endl;

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

int Bouncingball::bouncingBall(double h, double bounce, double window){
    
    if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)
    {
        return -1;
    }
    double& currentPosition = h;
    unsigned int passedWindow = 0;
    while (currentPosition > window)
    {
        currentPosition *= bounce;
        passedWindow++;
    }
    return passedWindow * 2 - 1;
}


int main(){
    LOG(Bouncingball::bouncingBall(3, 0.66, 1.5)); //Should be 3
}