#include <iostream>
#include "TempertureStreatgy.hpp"
#include "TempSensor.hpp"
int main()
{
    std::cout << "the application is started" << std::endl;
    smartdoor::TempSensor obj;
    obj.getTemp();
    return 0;
}
