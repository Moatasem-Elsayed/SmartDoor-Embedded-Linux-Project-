#include <iostream>
#include "TempertureStreatgy.hpp"
#include <thread>
#include <chrono>
#include <memory>
int main()
{
    std::cout << "the application is started " << std::endl;
    std::unique_ptr<smartdoor::IDoorStreatgy> doorExecuter = std::make_unique<smartdoor::TempertureStreatgy>();
    std::cout << "the application is executed " << std::endl;
    doorExecuter->execute();
    return 0;
}
