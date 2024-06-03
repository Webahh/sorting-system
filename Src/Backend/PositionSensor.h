#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include "DigitalPart.h"

namespace so {
    class PositionSensor : public DigitalPart
    {
        public:

            void updateLeft();
            void updateRight();
            void reset();
            int getPosition();

        protected:

        private:

            int m_position = 0; 
            bool m_lastState = false;
    };

}
#endif //POSITIONSENSOR_H