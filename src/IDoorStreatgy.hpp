
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
namespace smartdoor
{
    class IDoorStreatgy
    {

    public:
        IDoorStreatgy();
        virtual ~IDoorStreatgy() = default;
        virtual void execute() = 0;

    private:
    };
}
