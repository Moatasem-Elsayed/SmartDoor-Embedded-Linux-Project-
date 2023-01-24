
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:28:10 PM EET
brief:
*/
#include "FacadeResourceManager.hpp"

namespace smartdoor
{
    FacadeResourceManager::FacadeResourceManager() : m_Servo(std::make_unique<Servo>()), m_Temp(std::make_unique<TempSensor>()) {}
    FacadeResourceManager::~FacadeResourceManager() {}

    bool FacadeResourceManager::isSensorvalid()
    {
        bool flag = false;
        int value = m_Temp->getTemp();
        if (value > 35)
        {
            // high
        }
        else if (value > 30)
        {
            flag = true;
        }
        else
        {
            // normal
        }
        return flag;
    }

    void FacadeResourceManager::setDoor(DoorState state)
    {
        switch (state)
        {
        case DoorState::OPEN_DOOR:
            m_Servo->open();

            break;
        case DoorState::CLOSE_DOOR:
            m_Servo->close();
            break;

        default:
            break;
        }
    }
}
