#include "sensoric/PositionSensor.h"

namespace so {
            void PositionSensor::updateLeft()
            {
                if(getEvent()) {
                    m_position--;

                }
            }

            void PositionSensor::updateRight()
            {
                if(getEvent()) {
                    m_position++;
                }
            }

            void PositionSensor::reset(){
                m_position = 0;
            }

            int PositionSensor::getPosition() const{
                return m_position;
            }
}
