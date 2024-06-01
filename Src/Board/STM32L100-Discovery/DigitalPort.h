#ifndef DIGITALPORT_H
#define DIGITALPORT_H

//#include "Part.h"
//Part.h müsste die Embsyslib includen

class DigitalPort //: public Part
{
    public:
        virtual bool getState() = 0;
    protected:

    private:
};

#endif // DIGITALPORT_H