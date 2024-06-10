#pragma once

#include "Backend/Motor"
#include "Backend/PositionSensor"
#include "Backend/DigitalPart"
#include "Backend/AirVent"

namespace so {
    class Crane {
    public:

        void turnLeft();
        void turnRight();
        void halt();

        void updatePosition();
        void resetPosition();
        void getPosition();

        void raiseArm();
        void lowerArm();

        void enablePad();
        void disablePad();

    private:
        Motor m_motor;
        PositionSensor m_positionSensor;
        DigitatPart m_endswitch;
        AirVent m_arm;
        AirVent m_pad;
    }
}