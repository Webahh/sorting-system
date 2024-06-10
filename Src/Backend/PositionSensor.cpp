#include "PositionSensor.h"

namespace so {
            void PositionSensor::updateLeft()
            {
                if(getState() != m_lastState) {
                    m_lastState = getState();
                    m_position--;

                }
            }

            void PositionSensor::updateRight()
            {
                if(getState() != m_lastState) {
                    m_lastState = getState();
                    m_position++;

                }
            }

            void PositionSensor::reset(){
                m_position = 0;
            }

            int PositionSensor::getPosition(){
                return m_position;
            }
}