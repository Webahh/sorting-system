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
  disp.printf(0,0,__DATE__ " " __TIME__);
  terminal.printf( __DATE__ " " __TIME__ "\r\n" );

  int  num = 0;

  myTimerTask timerTask( taskManager );
  myRtosTask  rtosTask ( rtos );


//***************************Test Area********************************

  //EmbSysLib::Hw::Port::Pin test(portA,12,Port::In);
  Digital    btn0    ( portC, 0, Digital::InPU,  1 );
  Digital    btn1    ( portC, 1, Digital::InPU,  1 );

  int val=-1;
  Adc_Mcu  adc( timer );
  BYTE AdcChannelList[] =  {2,3,6,7,12,13,14,15};

  for (int i = 0; i < sizeof(AdcChannelList);i++){
	  adc.enable(AdcChannelList[i]);
  }

//***************************Test Area********************************

  rtosTask.start();

  while(1)
  {
    if( char *str = terminal.getString() )
    {
      terminal.printf( "\r\n=>%s\r\n", str );
    }

    switch( enc.getEvent() )
    {
        case DigitalEncoder::LEFT:     num -= 1; break;
        case DigitalEncoder::RIGHT:    num += 1; break;
        case DigitalEncoder::CTRL_DWN: num  = 0; break;
        default:                                 break;
    }

    if( btnA.getEvent() == Digital::ACTIVATED )
    {
        led0.toggle();
    }


    //disp.printf( 1, 0, "timer:      %-5d ", timerTask.cnt );
    //disp.printf( 2, 0, "rtos:       %-5d ", rtosTask.cnt  );
    disp.printf( 1, 0, "Port:        %-5d ", num           );





   if( btn0.getEvent() == Digital::ACTIVATED )
    {
        led0.toggle();
        Digital    test    ( portB, num, Digital::Out,  1 );


    }

    if( btn1.getEvent() == Digital::ACTIVATED )
     {
         led0.toggle();
         Digital    test    ( portB, num, Digital::Out,  0 );
     }



//output
    led0.toggle();
    val=adc.get(num);

    disp.printf( 2, 0, "Value:        %-5d ",     val);

    disp.refresh();
  }
}
//EOF

