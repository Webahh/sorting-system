#ifndef DIGITALPORT_H
#define DIGITALPORT_H

//Part.h müsste die Embsyslib includen
namespace so {
    class DigitalPart 
    {
        public:
            DigitalPart(const EmbSysLib::Dev::Digital& digitalPort)
            : m_digitalPort(digitalPort){

            }

            virtual bool getState(); 

        private:
            EmbSysLib::Dev::Digital& m_digitalPort;
    };
}
#endif // DIGITALPORT_H