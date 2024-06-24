#pragma once

#include "EmbSysLib.h"
#include "Frontend/Crane.h"
#include "Backend/PressureController.h"

#include <string>

using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;
using namespace so;

EmbSysLib::Hw::PinConfig::MAP EmbSysLib::Hw::PinConfig::table[] =
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
	  ADC12_IN2_PA2,
	  ADC12_IN6_PA6,
	  ADC12_IN3_PA3,

	  END_OF_TABLE
	};


//TIMER
Timer_Mcu app_timer(Timer_Mcu::TIM_10, 10000L);
TaskManager app_taskManager(app_timer);

Timer_Mcu time_timer(Timer_Mcu::TIM_10, 1000L);
TaskManager time_taskManager(time_timer);

//--------------------------------------------------------------------------------------//
//PORTS
Port_Mcu   portA( Port_Mcu::PA );
Port_Mcu   portB( Port_Mcu::PB );
Port_Mcu   portC( Port_Mcu::PC );
Port_Mcu   portD( Port_Mcu::PD );

//OUT
Digital enable( portD, 2, Digital::Out, 1 );
Digital pressureControllerPort(portB, 5, Digital::Out, 0);
Digital motorLeftPort(portB, 1, Digital::Out, 0);
Digital motorRightPort(portB, 0, Digital::Out, 0);
Digital armVentPort(portB, 6, Digital::Out, 0);
Digital padVentPort(portB, 9, Digital::Out, 0);

//IN
Digital positionSensorPort(portC, 2, Digital::InPU, 0);
Digital endswitchPort(portA, 7, Digital::InPU, 1);
Digital lightBarrierPort(portC, 3, Digital::InPU, 0);

Digital rotA(portA, 8, Digital::InPU, 0);
Digital rotB(portA, 1, Digital::InPU, 0);
Digital rotCtrl(portA, 15, Digital::InPU, 0);

//Analog
 Adc_Mcu adc(app_timer);
const int colorSensorPort = 3;




