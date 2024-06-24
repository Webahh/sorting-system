#include "App.h"
#include "config.h"
#include "SOControllerBase.h"
#include "Backend/PressureController.h"
#include "Frontend/Crane.h"
#include "Backend/ColorSensor.h"

namespace so {
    void App::init(){
        m_soController = new SOController();
        m_pressureController = new PressureController(pressureControllerPort);
        m_crane = new Crane(
		Motor(motorLeftPort, motorRightPort),
		PositionSensor(positionSensorPort),
		DigitalPart(endswitchPort),
		AirVent(armVentPort),
		AirVent(padVentPort));

        m_colorSensor = new ColorSensor(adc, colorSensorPort);
        m_lightBarrier = new DigitalPart(lightBarrierPort);
        
        m_pressureController->enable();
    }

    void App::update(){
        if(!isValid())
            return;

        m_crane->updatePosition(); 
        m_soController->update();
    }

    void App::terminate(){
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
        delete m_colorSensor;
        delete m_lightBarrier;
    }

    bool App::isValid() const {
        return m_soController && m_pressureController && m_crane;
    }

    SOController* App::getSOController() const{
        return m_soController;
    }

    PressureController* App::getPressureController() const{
        return m_pressureController;
    }

    Crane* App::getCrane() const{
        return m_crane;
    }

    ColorSensor* App::getColorSensor() const {
        return m_colorSensor;
    }

    DigitalPart* App::getLightBarrier() const {
        return m_lightBarrier;
    }
}
