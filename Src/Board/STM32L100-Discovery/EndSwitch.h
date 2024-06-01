#ifndef ENDSWITCH_H
#define ENDSWITCH_H

#include "DigitalPort.h"


class EndSwitch : public DigitalPort
{
    public:
        bool getState()
        {
            //Digital test (portB, 7, Digital::Out, 0); //Port 7 Entposition Kran
        }
        
    protected:

    private:
};

#endif // ENDSWITCH_H