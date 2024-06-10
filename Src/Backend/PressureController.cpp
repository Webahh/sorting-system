#include "PressureController.h" 

namespace so {

    void PressureController::enable(){
        m_portPressure.set(true);
    }

    void PressureController::disable(){
        m_portPressure.set(false);
    }
}