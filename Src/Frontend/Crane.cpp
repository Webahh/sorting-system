#include "Crane.h"

namespace so {

    void Crane::turnLeft(){
        m_motor.turnLeft();
    }

    void Crane::turnRight(){
        m_motor.turnLeft();
    }

    void Crane::halt(){
        m_motor.halt();
    }

    void Crane::updatePosition(){
        if(m_endswitch.getState()){
            m_positionSensor.reset();
            return;
        }

       if(m_motor.getDirection() == MotorDirection::LEFT_TURN){
            m_positionSensor.updateLeft();
            return;
       } else if(m_motor.getDirection() == MotorDirection::RIGHT_TURN){
            m_positionSensor.updateRight();
            return;
       }
    }

    void Crane::getPosition(){
        return m_positionSensor.getPosition();
    }

    void Crane::raiseArm() {
        m_arm.open();
    }

    void Crane::lowerArm() {
        m_arm.close();
    }

    void Crane::enablePad() {
        m_pad.open();
    }

    void Crane::disablePad() {
        m_pad.close();
    }

}