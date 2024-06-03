#pragma once

#include "EmbSysLib.h"

namespace so {
    class Motor {
    public:

        Motor(EmbSysLib::Dev::Digital& portTurnLeft, EmbSysLib::Dev::Digital& portTurnRight)
            : m_portTurnLeft(portTurnLeft)
            , m_portTurnRight(portTurnRight)
        {}      

        void turnLeft();
        void turnRight();
        void halt();

    private:
        EmbSysLib::Dev::Digital& m_portTurnLeft;
        EmbSysLib::Dev::Digital& m_portTurnRight;
    };
}

