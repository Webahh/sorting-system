#include "movement/Crane.h"

namespace so {

    void Crane::turnLeft(){
        m_motor.turnLeft();
    }

    void Crane::turnRight(){
        m_motor.turnRight();
    }

    void Crane::halt(){
        m_motor.halt();
    }

    void Crane::updatePosition(){
        if(m_endswitch.getState()){
            m_positionSensor.reset();
        }
        else if(m_motor.getDirection() == MotorDirection::LEFT_TURN){
            m_positionSensor.updateLeft();
       } else if(m_motor.getDirection() == MotorDirection::RIGHT_TURN){
            m_positionSensor.updateRight();
       }
    }

    int Crane::getPosition() const{
        return m_positionSensor.getPosition();
    }

    void Crane::raiseArm() {
        m_arm.close();
    }

    void Crane::lowerArm() {
        m_arm.open();
    }

    void Crane::enablePad() {
        m_pad.open();
    }

    void Crane::disablePad() {
        m_pad.close();
    }

    const Motor& Crane::getMotor() const{
        return m_motor;
    }
    const DigitalPart& Crane::getEndswitch() const{
        return m_endswitch;
    }
    const AirVent& Crane::getArmVent() const{
        return m_arm;
    }
    const AirVent& Crane::getPadVent() const{
        return m_pad;
    }

}
