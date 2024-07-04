#include "movement/AirVent.h"

namespace so {

    void AirVent::open(){
        m_portAirVent.set(true);
    }

    void AirVent::close(){
        m_portAirVent.set(false);
    }

    bool AirVent::isOpen() const{
    	return m_portAirVent.get();
    }
}
