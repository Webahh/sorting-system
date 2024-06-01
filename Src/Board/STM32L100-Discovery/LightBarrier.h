#ifndef LIGHTBARRIER_H
#define LIGHTBARRIER_H

#include "DigitalPort.h"

class LightBarrier : DigitalPort
{
    public:
        bool getState()
        {
            //Digital test (portB, 13, Digital::Out, 0);
        }
    protected:

    private:

};

#endif //LIGHTBARRIER_H