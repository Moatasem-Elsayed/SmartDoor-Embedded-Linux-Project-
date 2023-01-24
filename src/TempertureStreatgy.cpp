
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:27:38 PM EET
brief:
*/
#include "TempertureStreatgy.hpp"
#include <csignal>
#include <iostream>
#include <thread>

namespace smartdoor
{
    bool smartdoor::TempertureStreatgy::run = true;
    void signalHandler(int signum)
    {
        std::cout << "Interrupt signal (" << signum << ") received.\n";
        smartdoor::TempertureStreatgy::run = false;
    }

    TempertureStreatgy::TempertureStreatgy() : m_resourceManager(std::make_unique<FacadeResourceManager>()) {}
    TempertureStreatgy::~TempertureStreatgy() {}

    void TempertureStreatgy::execute()
    {
        std::cout << __FUNCTION__ << std::endl;
        signal(SIGINT, signalHandler);
        while (run)
        {
            if (m_resourceManager->isSensorvalid())
            {
                m_resourceManager->setDoor(DoorState::OPEN_DOOR);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                m_resourceManager->setDoor(DoorState::CLOSE_DOOR);
            }
            else
            {
                m_resourceManager->setDoor(DoorState::CLOSE_DOOR);
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}
