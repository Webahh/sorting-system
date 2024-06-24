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


//TIMER
static Timer_Mcu app_timer(Timer_Mcu::TIM_10, 10000L);
static TaskManager app_taskManager(app_timer);

static Timer_Mcu time_timer(Timer_Mcu::TIM_10, 1000L);
static TaskManager time_taskManager(time_timer);

//--------------------------------------------------------------------------------------//
//PORTS
static Port_Mcu   portA( Port_Mcu::PA );
static Port_Mcu   portB( Port_Mcu::PB );
static Port_Mcu   portC( Port_Mcu::PC );
static Port_Mcu   portD( Port_Mcu::PD );

//OUT
static Digital enable( portD, 2, Digital::Out, 1 );
static Digital pressureControllerPort(portB, 5, Digital::Out, 0);
static Digital motorLeftPort(portB, 1, Digital::Out, 0);
static Digital motorRightPort(portB, 0, Digital::Out, 0);
static Digital armVentPort(portB, 6, Digital::Out, 0);
static Digital padVentPort(portB, 9, Digital::Out, 0);

//IN
static Digital positionSensorPort(portC, 2, Digital::InPU, 0);
static Digital endswitchPort(portA, 7, Digital::InPU, 1);
static Digital lightBarrierPort(portC, 3, Digital::InPU, 1);

static Digital rotA(portA, 8, Digital::InPU, 0);
static Digital rotB(portA, 1, Digital::InPU, 0);
static Digital rotCtrl(portA, 15, Digital::InPU, 0);

//Analog
static Adc_Mcu adc(app_timer);
static const int colorSensorPort = 6;




