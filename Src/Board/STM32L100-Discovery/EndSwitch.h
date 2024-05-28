#ifndef ENDSWITCH_H
#define ENDSWITCH_H

#include "Digital.h"


class EndSwitch : public Digital
{
    public:
        bool getState()
        {
            Digital test (portB, num, Digital::Out, 0);
        }
    protected:

    private:
};

#endif // ENDSWITCH_H