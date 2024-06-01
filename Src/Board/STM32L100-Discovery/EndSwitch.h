#ifndef ENDSWITCH_H
#define ENDSWITCH_H

#include "DigitalPort.h"


class EndSwitch : public DigitalPort
{
    public:
        bool getState()
        {
            //Digital test (portB, 7, Digital::Out, 0);
        }
        
    protected:

    private:
};

#endif // ENDSWITCH_H