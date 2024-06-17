#pragma once

#include "Src/Backend/Motor.h"
#include "Src/Backend/PositionSensor.h"
#include "Src/Backend/DigitalPart.h"
#include "Src/Backend/AirVent.h"

namespace so {
    class Crane {
    public:

    	Crane(const Motor& motor, const PositionSensor& positionSensor, const DigitalPart& endswitch, const AirVent& arm, const AirVent& pad)
    		: m_motor(motor)
    		, m_positionSensor(positionSensor)
    		, m_endswitch(endswitch)
    		, m_arm(arm)
    		, m_pad(pad)
    	{}

        void turnLeft();
        void turnRight();
        void halt();

        void updatePosition();
        void resetPosition();
        int getPosition() const;

        void raiseArm();
        void lowerArm();

        void enablePad();
        void disablePad();

        Motor m_motor;
        PositionSensor m_positionSensor;
        DigitalPart m_endswitch;
        AirVent m_arm;
        AirVent m_pad;
    };
}
