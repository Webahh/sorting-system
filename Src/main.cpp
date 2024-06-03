//*******************************************************************
#include "EmbSysLib.h"

#include "Backend/Motor.h"

using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;

Port_Mcu   portA( Port_Mcu::PA );
Port_Mcu   portB( Port_Mcu::PB );
Port_Mcu   portC( Port_Mcu::PC );
Port_Mcu   portD( Port_Mcu::PD );

Digital  enable( portD, 2, Digital::Out, 1 );

Digital motorLeft(portB, 1, Digital::Out, 0);
Digital motorRight(portB, 0, Digital::Out, 0);

//*******************************************************************
int main(void)
{
	so::Motor m = so::Motor(motorLeft, motorRight);
	m.turnRight();

	while(1){};

	return 0;
}


