#include "PressureController.h" 

namespace so {

void PressureController::enable(){
    	m_bEnable = true;
		if(!m_portPressure.get()){
			m_portPressure.set(true);
		}
    }

    void PressureController::disable(){
    	m_bEnable = false;
    	if(m_portPressure.get()){
    		m_portPressure.set(false);
    	}
    }

    void PressureController::calibrate(){
    	m_scale = m_pressureSensor.getValue();
    }

    // Hilfsfunktion
    int PressureController::getPressure() const{
    	int jesus = m_pressureSensor.getValue();

    	return jesus-m_scale;
    }

    void PressureController::checkPressure(){
    	if(m_bEnable){
			if (PressureController::getPressure()>=8500){ // Top Histerese
				m_portPressure.set(false);
			}

			if (PressureController::getPressure()<=5500){ // Bottom Histerese
				m_portPressure.set(true);
			}
    	}
    }
}
