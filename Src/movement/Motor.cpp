#include "movement/Motor.h"

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
        m_portTurnRight.set(false);
    }

    MotorDirection Motor::getDirection() const{
        if(m_portTurnLeft.get()){
            return MotorDirection::LEFT_TURN;
        } else if(m_portTurnRight.get()){
            return MotorDirection::RIGHT_TURN;
        } else {
            return MotorDirection::HALT;
        }
    }
}
