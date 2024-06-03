#include "Motor.h" 

namespace so {

    void Motor::turnLeft(){
        m_portTurnRight.set(false);
        m_portTurnLeft.set(true);
    }

    void Motor::turnRight(){
        m_portTurnLeft.set(false);
        m_portTurnRight.set(true);
    }

    void Motor::halt(){
        m_portTurnLeft.set(false);
        m_portTurnLeft.set(false);
    }
}