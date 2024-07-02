#include "App.h"
#include "Backend/PressureController.h"
#include "Backend/Crane.h"
#include "Backend/ColorSensor.h"
#include "Backend/AirPressureSensor.h"
#include "SOControllerBase.h"
#include "events.h"
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

extern Digital btn0;
extern DigitalEncoderRotaryknob encoderWheel;

//Analog
extern  Adc_Mcu adc;
const int colorSensorPort = 3;
const int airPressureSensorPort = 2;
const int screenSize = 4;


namespace so {
    void App::init(){
        m_soController = new SOController();
        m_pressureController = new PressureController(pressureControllerPort, AirPressureSensor(adc, airPressureSensorPort));
        m_crane = new Crane
        		(
        			Motor(motorLeftPort, motorRightPort),
					PositionSensor(positionSensorPort),
					DigitalPart(endswitchPort),
					AirVent(armVentPort),
					AirVent(padVentPort)
				);
        m_colorSensor = new ColorSensor(adc, colorSensorPort);
        m_lightBarrier = new DigitalPart(lightBarrierPort);
        m_screen = new Screen(screenSize);
        System::delayMilliSec(100);
        m_pressureController->calibrate();
    }

    void App::update(){
        if(!isValid())
            return;

        m_crane->updatePosition(); 
        m_soController->update();
        m_pressureController->checkPressure();

        handleEvents();

        m_screen->update();
        m_screen->render();
    }

    bool App::forwardEvent(const EventType& eventType) {
    	if(m_screen){
    		return m_screen->dispatchEvent(eventType);
    	}

    	return false;
    };

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


    void App::handleEvents(){
    	switch( encoderWheel.getEvent() )
		{
			case DigitalEncoder::LEFT:
				dispatchEvent(scrollDownEventType);
				break;
			case DigitalEncoder::RIGHT:
				dispatchEvent(scrollUpEventType);
				break;
			case DigitalEncoder::CTRL_DWN:
				dispatchEvent(menuBtnClickEventType);
				break;
			default:
				break;
		}

    	if(btn0.getEvent()){
    		dispatchEvent(menuBtnActionEventType);
    	}
    }

    bool App::isValid() const {
        return m_soController && m_pressureController && m_crane && m_screen;
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

    Screen* App::getScreen() const{
    	return m_screen;
    }
}
