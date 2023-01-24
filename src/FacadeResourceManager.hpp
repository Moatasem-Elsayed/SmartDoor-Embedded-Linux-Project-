
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:28:09 PM EET
brief:
*/
#include <iostream>
#include <memory>
#include "Servo.hpp"
#include "TempSensor.hpp"
namespace smartdoor
{
    enum class DoorState : unsigned char
    {
        OPEN_DOOR,
        CLOSE_DOOR
    };
    class FacadeResourceManager
    {

    public:
        FacadeResourceManager();
        ~FacadeResourceManager();
        bool isSensorvalid();
        void setDoor(DoorState state);

    private:
        std::unique_ptr<Servo> m_Servo;
        std::unique_ptr<TempSensor> m_Temp;
    };
}
