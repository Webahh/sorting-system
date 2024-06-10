#include "AirVent.h"

namespace so {

    void AirVent::open(){
        m_portAirVent.set(true);
    }

    void AirVent::close(){
        m_portAirVent.set(false);
    }
}