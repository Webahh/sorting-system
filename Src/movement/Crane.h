#pragma once

#include "movement/Motor.h"
#include "movement/AirVent.h"
#include "sensoric/PositionSensor.h"
#include "sensoric/DigitalPart.h"


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

        const Motor& getMotor() const;
        const DigitalPart& getEndswitch() const;
        const AirVent& getArmVent() const;
        const AirVent& getPadVent() const;

    private:
        Motor m_motor;
        PositionSensor m_positionSensor;
        DigitalPart m_endswitch;
        AirVent m_arm;
        AirVent m_pad;
    };
}
