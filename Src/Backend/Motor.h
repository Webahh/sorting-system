#pragma once

#include "EmbSysLib.h"
#include "Base/Part.h"

namespace ss {
    class Motor : public Part {
    public:

        Motor(const EmbSysLib::Dev::Digital& portTurnLeft, const EmbSysLib::Dev::Digital& portTurnRight)
            : m_portTurnLeft(portTurnLeft)
            , m_portTurnRight(portTurnRight)
        {}      

        virtual void enable();
	    virtual void disable();

        void turnLeft();
        void turnRight();
        void halt();

    private:
        EmbSysLib::Dev::Digital m_portTurnLeft;
        EmbSysLib::Dev::Digital m_portTurnRight;
    };
}

