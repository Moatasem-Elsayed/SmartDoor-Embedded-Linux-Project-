
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:27:30 PM EET
brief:
*/
#include "IDoorStreatgy.hpp"
#include "FacadeResourceManager.hpp"
namespace smartdoor
{
    class TempertureStreatgy : public IDoorStreatgy
    {

    public:
        TempertureStreatgy();
        ~TempertureStreatgy();
        void execute() override;
        friend void signalHandler(int signum);

    private:
        static bool run;
        std::unique_ptr<FacadeResourceManager> m_resourceManager;
    };
}
