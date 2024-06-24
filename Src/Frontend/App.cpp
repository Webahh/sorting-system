#include "App.h"
//#include "config.h"
#include "SOControllerBase.h"
#include "Backend/PressureController.h"
#include "Frontend/Crane.h"
#include "Backend/ColorSensor.h"
#include "EmbSysLib.h"

using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;
using namespace so;

extern Port_Mcu   portA;
extern Port_Mcu   portB;
extern Port_Mcu   portC;
extern Port_Mcu   portD;

//OUT
extern Digital enable;
extern Digital pressureControllerPort;
extern Digital motorLeftPort;
extern Digital motorRightPort;
extern Digital armVentPort;
extern Digital padVentPort;

//IN
extern Digital positionSensorPort;
extern Digital endswitchPort;
extern Digital lightBarrierPort;

extern Digital rotA;
extern Digital rotB;
extern Digital rotCtrl;

//Analog
extern  Adc_Mcu adc;
const int colorSensorPort = 3;


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
