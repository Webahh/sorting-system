#include "movement/PressureController.h"

namespace so {

void PressureController::enable(){
    	m_bEnable = true;
    }

    void PressureController::disable(){
    	m_bEnable = false;
    }

    void PressureController::calibrate(){
    	m_scale = m_pressureSensor.getValue();
    }

    int PressureController::getPressure() const{
    	m_pressureSensor.getValue();

    	return m_pressureSensor.getValue()-m_scale; // Good Bye Jesus!
    }

    void PressureController::checkPressure(){
    	if(m_bEnable){
			if (PressureController::getPressure()>=8500){ // Top Histerese
				m_portPressure.set(false);
			}

			if (PressureController::getPressure()<=5500){ // Bottom Histerese
				m_portPressure.set(true);
			}
    	}else{
    		m_portPressure.set(false);
    	}
    }
}
