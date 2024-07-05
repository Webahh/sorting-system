#include "movement/PressureController.h"
#include <string>

namespace so {

void PressureController::enable(){
    	m_bEnable = true;
    }

    void PressureController::disable(){
    	m_bEnable = false;
    }

    int PressureController::getPressure() const{
    	m_pressureSensor.getValue();

    	return m_pressureSensor.getValue(); // Good Bye Jesus!
    }

    std::string PressureController::showPressure(){
    	std::string s = "";
    	if(m_enoughPressure){
    		s = "OK";
    	} else{
    		s = "PUMPING";
    	}
    	return s;
    }

    void PressureController::checkPressure(){
    	if(m_bEnable){
			if (PressureController::getPressure()>=20000){ // Top Histerese
				m_portPressure.set(false);
				m_enoughPressure = true;
			}

			if (PressureController::getPressure()<=18000){ // Bottom Histerese
				m_portPressure.set(true);
				m_enoughPressure = false;
			}
    	}else{
    		m_portPressure.set(false);
    	}
    }
}
