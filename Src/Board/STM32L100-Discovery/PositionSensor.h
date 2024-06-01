#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include "DigitalPort.h"

class PositionSensor : DigitalPort
{
    public:
        bool getState()
        {
            //Digital test (portB, 3, Digital::Out, 0); //Port 3 Positionserkennung
        }
        
        float getPosition()
        {
            return position;
        }

        void update()
        {
            //Wie genau habt ihr euch das vorgestellt?
            //Wird das in einer While aufgerufen?
            //Wo soll geprüft werden ob sich der Bums nach links oder rechts dreht?
        }

        void reset()
        {
            position = 0.0f;
        }

    protected:

    private:
        float position = 0.0f; 
        //Sicher das wir einen Float haben wollen? Vergleich etc. wird umständlicher
};

#endif //POSITIONSENSOR_H