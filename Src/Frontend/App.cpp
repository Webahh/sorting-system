#include "App.h"
#include "SOControllerBase.h"
#include "Src/config.h"
#include "PressureController.h"
#include "Crane.h"

namespace so {
    void init(){
        m_soController = new SOController();
        m_pressureController = new PressureController(pressureControllerPort);
        m_crane = new Crane(
		Motor(motorLeftPort, motorRightPort),
		PositionSensor(positionSensorPort),
		DigitalPart(endswitchPort),
		AirVent(armVentPort),
		AirVent(padVentPort));

        m_pressureController->enable();
    }

    void update(){
        if(!isValid())
            return;

        m_crane->updatePosition(); 
        m_soController->update();
    }

    void terminate(){
        if(m_pressureController){
            m_pressureController->enable();
        }

        if(m_crane){
            m_crane->halt();
            m_crane->raiseArm();
            m_crane->disablePad();
        }

        delete m_pressureController;
        delete m_crane;
    }

    bool isValid() const {
        return m_soController && m_pressureController && m_crane;
    }

    SOController* getSOController const(){
        return m_soController;
    }

    PressureController* getPressureController const(){
        return m_pressureController;
    }

    SOController* getCrane const(){
        return m_soController;
    }
}