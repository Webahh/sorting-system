#include "App.h"
#include "Backend/PressureController.h"
#include "Backend/Crane.h"
#include "Backend/ColorSensor.h"
#include "Backend/AirPressureSensor.h"
#include "SOControllerBase.h"
#include "AutoStates.h"
#include "ManualStates.h"
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

extern Digital btn1;
extern Digital btn2;
extern Digital btn3;
extern Digital btn4;

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
        m_menu = new Menu(screenSize);
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

        m_menu->update();
        m_menu->render();
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


    void App::handleEvents(){

    	switch(App::get().getSortMode()){
			case SortMode::OFF:
			{
				switch(encoderWheel.getEvent())
				{
					case DigitalEncoder::LEFT:     m_menu->onMoveDisplayUp(); break;
					case DigitalEncoder::RIGHT:    m_menu->onMoveDisplayDown(); break;
					default:                                 break;
				}

				if(btn4.getEvent() == Digital::ACTIVATED){
					m_sortMode = SortMode::AUTO;
					m_soController->reset();
					m_soController->run(SOState(AutoStates::stateMoveToLoader));
				}

				if(btn3.getEvent() == Digital::ACTIVATED){
					m_sortMode = SortMode::MANUAL;
					m_soController->reset();
					m_pressureController->enable();
				}
			}
				break;
			case SortMode::AUTO:
				switch(encoderWheel.getEvent())
				{
					case DigitalEncoder::LEFT:     m_menu->onMoveDisplayUp(); break;
					case DigitalEncoder::RIGHT:    m_menu->onMoveDisplayDown(); break;
					default:                                 break;
				}
				if(btn4.getEvent() == Digital::ACTIVATED){
					m_sortMode = SortMode::OFF;
					m_soController->reset();
				}
				break;
			case SortMode::MANUAL:
				{
					switch(encoderWheel.getEvent())
					{
						case DigitalEncoder::LEFT:
							m_soController->run(SOState(ManualStates::turnLeft));
						break;
						case DigitalEncoder::RIGHT:
							m_soController->run(SOState(ManualStates::turnRight));
							break;
						case DigitalEncoder::CTRL_DWN:
							m_soController->run(SOState(ManualStates::toggleArm));
							break;
						default:
							break;
					}

					if(btn3.getEvent() == Digital::ACTIVATED){
						m_sortMode = SortMode::OFF;
						m_soController->reset();
						m_pressureController->disable();
					}
				}
				break;
			default:
				break;

		}

    }

    bool App::isValid() const {
        return m_soController && m_pressureController && m_crane && m_menu;
    }

    SortMode App::getSortMode() const{
    	return m_sortMode;
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

    Menu* App::getMenu() const{
    	return m_menu;
    }
}
