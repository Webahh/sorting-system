#include "DigitalPart.h"

namespace so {

    bool DigitalPart::getState(){
        return m_digitalPort.get();
    }
}