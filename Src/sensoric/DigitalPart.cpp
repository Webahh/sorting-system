#include "sensoric/DigitalPart.h"

namespace so {

    bool DigitalPart::getState() const{
        return m_digitalPort.get();
    }

    bool DigitalPart::getEvent() const{
            return m_digitalPort.getEvent();
    }
}
