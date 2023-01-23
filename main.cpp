#include <iostream>
#include "TempertureStreatgy.hpp"
#include "TempSensor.hpp"
int main()
{
    std::cout << "the application is started" << std::endl;
    smartdoor::TempSensor obj;
    
    std::cout << "the temp value is " << obj.getTemp() << std::endl;

    return 0;
}
