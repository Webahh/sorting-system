#pragma once

#include "EmbSysLib.h"

//Part.h müsste die Embsyslib includen
namespace so {
    class DigitalPart 
    {
        public:
            DigitalPart(EmbSysLib::Dev::Digital& digitalPort)
            : m_digitalPort(digitalPort){

            }

            virtual bool getState() const;
            virtual bool getEvent() const;


        private:
            EmbSysLib::Dev::Digital& m_digitalPort;
    };
}

