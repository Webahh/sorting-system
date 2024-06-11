#pragma once

#include "EmbSysLib.h"

namespace so {

    enum MotorDirection{
        LEFT_TURN = 0,
        RIGHT_TURN = 1,
        HALT = 2,
    };

    class Motor {
    public:

        Motor(EmbSysLib::Dev::Digital& portTurnLeft, EmbSysLib::Dev::Digital& portTurnRight)
            : m_portTurnLeft(portTurnLeft)
            , m_portTurnRight(portTurnRight)
        {}      

        void turnLeft();
        void turnRight();
        void halt();

        MotorDirection getDirection()const;

    private:
        EmbSysLib::Dev::Digital& m_portTurnLeft;
        EmbSysLib::Dev::Digital& m_portTurnRight;
    };
}

