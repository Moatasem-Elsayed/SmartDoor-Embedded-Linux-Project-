#include <iostream>
#include "TempertureStreatgy.hpp"
#include "TempSensor.hpp"
#include "Servo.hpp"
#include <thread>
#include <chrono>
int main()
{
    std::cout << "the application is started" << std::endl;
    smartdoor::TempSensor obj;
    smartdoor::Servo sv;
    sv.open();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "the temp value is " << obj.getTemp() << std::endl;
    sv.close();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    sv.open();

    return 0;
}
