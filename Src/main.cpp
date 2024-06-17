//*******************************************************************
#include "EmbSysLib.h"

#include "Frontend/Crane.h"
#include "Hardware/Peripheral/Display/DisplayChar_DIP204spi.cpp"
#include "Src/Backend/PressureController.h"
#include "Module/Rtos/Rtos.h"

#include <string>

using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;

using namespace so;


Port_Mcu   portA( Port_Mcu::PA );
Port_Mcu   portB( Port_Mcu::PB );
Port_Mcu   portC( Port_Mcu::PC );
Port_Mcu   portD( Port_Mcu::PD );

Digital  enable( portD, 2, Digital::Out, 1 );

Digital pressureControllerPort(portB, 5, Digital::Out, 0); //

Digital motorLeftPort(portB, 1, Digital::Out, 0);
Digital motorRightPort(portB, 0, Digital::Out, 0);

Digital positionSensorPort(portC, 2, Digital::InPU, 0);
Digital endswitchPort(portA, 7, Digital::InPU, 1);
Digital lbPort(portC, 3, Digital::InPU, 0); //

Digital buttonS2(portC, 1, Digital::In, 0); //
Digital buttonS3(portC, 6, Digital::In, 0); //

Digital armVentPort(portB, 6, Digital::Out, 0);
Digital padVentPort(portB, 9, Digital::Out, 0);

PressureController pressureController(pressureControllerPort); //

Crane crane(
		Motor(motorLeftPort, motorRightPort),
		PositionSensor(positionSensorPort),
		DigitalPart(endswitchPort),
		AirVent(armVentPort),
		AirVent(padVentPort)
);

Timer_Mcu timer(Timer_Mcu::TIM_10, 10000L);
TaskManager taskManager(timer);

PinConfig::MAP PinConfig::table[] =
{
  // SPI
  SPI2_MOSI_PB15,
  SPI2_MISO_PB14,
  SPI2_SCK_PB13,
  SPI2_NSS_PB12,

  // UART
  USART1_TX_PA9,
  USART1_RX_PA10,

  // ADC
  ADC12_IN0_PA0,
  ADC12_IN1_PA1,
    ADC12_IN2_PA2,
    ADC12_IN3_PA3,
    ADC12_IN4_PA4,
    ADC12_IN5_PA5,
    ADC12_IN6_PA6,
    ADC12_IN7_PA7,
    ADC12_IN8_PB0,
    ADC12_IN9_PB1,
    ADC12_IN10_PC0,
    ADC12_IN11_PC1,
    ADC12_IN12_PC2,
    ADC12_IN13_PC3,
    ADC12_IN14_PC4,
    ADC12_IN15_PC5,

  END_OF_TABLE
};

Digital rotA(portA, 8, Digital::InPU, 0);
Digital rotB(portA, 1, Digital::InPU, 0);
Digital rotCtrl(portA, 15, Digital::InPU, 0);

DigitalEncoderRotaryknob enc(&rotA, &rotB, &rotCtrl, taskManager);

SPImaster_Mcu         spi          ( SPImaster_Mcu::SPI_2, SPImaster_Mcu::CR_1000kHz, SPImaster_Mcu::CPOL_H_CPHA_H );
SPImaster::Device     spiDevDisplay( spi, portB, 12 );
DisplayChar_DIP204spi dispHw       ( spiDevDisplay );
ScreenChar            disp         ( dispHw );


class myRtosTask : public Rtos::Task
{
  public:
    //---------------------------------------------------------------
    myRtosTask( Rtos &rtos )
    : Rtos::Task( rtos, 5000/* stack size*/ )
    {
		stateCrane = false;
		statePad = false;
		a = false;
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void )
    {
      while(1)
      {
		if(!a){
			if(stateCrane){
				crane.raiseArm();
				stateCrane = false;
				pause();
			}else{
				crane.lowerArm();
				stateCrane = true;

				pause();
			}
			a = true;
		}else{
			if(!statePad){
				crane.enablePad();
				statePad = true;
				pause();
			}else{
				crane.disablePad();
				statePad = false;
				pause();
			}
			a = false;
		}
	  }
	}

	bool stateCrane;
	bool statePad;
	bool a;
}; //class myRtosTask

//*******************************************************************
Rtos    rtos (    2,   // max num of tasks
               10 ); // time slice in us

//*******************************************************************
int main(void)
{

	while(endswitchPort.get() != 1){
		bool move = false;
		if(!move){
			crane.turnLeft();
			move = true;
		}
	}

	pressureController.enable();

	myRtosTask  rtosTask ( rtos );

	while(1){

		// Abbruchbedingung: es gibt keinen Stein mehr
		if(lbPort.get() != 1){
			pressureController.disable();
			exit(0);
		}

		crane.updatePosition();

		if(buttonS2.getEvent()){
			rtosTask.start();
		}

		

		//check for endposition
//		if(false && endswitchPort.get() == 1){
//			crane.halt();
//		}
//
//		// zum testen von den relevanten positionen
//		if(crane.getPosition() == 8){
//			crane.halt();
//		}
//
//		if(crane.getPosition() == 10){
//			crane.halt();
//		}
//
//		if(crane.getPosition() ==12){
//			crane.halt();
//		}
//
//		if(crane.getPosition() == 14){
//			crane.halt();
//		}

		// Abbruchbedingung: der Kran soll nicht überdreht
		if(crane.getPosition() >= 16){
			crane.halt();
		}

		switch(enc.getEvent()){
			case DigitalEncoder::LEFT:
				crane.turnLeft();
				break;
			case DigitalEncoder::RIGHT:
				crane.turnRight();
				break;
			case DigitalEncoder::CTRL_DWN:
				crane.halt();
				break;
			default:
				break;
		}
		disp.printf(0, 0, "endS State: %d", endswitchPort.get());
		disp.printf(1, 0, "Pos State: %d", positionSensorPort.get());
		disp.printf(2, 0, "lb State: %d", lbPort.get());
		disp.printf(3, 0, "Pos: %3d", crane.getPosition());

		disp.refresh();
	};

	return 0;
}


