//*******************************************************************
#include "EmbSysLib.h"
#include "Module/Rtos/Rtos.h"
#include "ReportHandler.h"
#include "config.h"


//*******************************************************************
class myTimerTask : public TaskManager::Task
{
  public:
    //---------------------------------------------------------------
    myTimerTask( TaskManager &taskManager )
    {
      cnt = 0;
      taskManager.add( this );
    }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      cnt++;
    }



    //---------------------------------------------------------------
    DWORD cnt;
};

//*******************************************************************
class myRtosTask : public Rtos::Task
{
  public:
    //---------------------------------------------------------------
    myRtosTask( Rtos &rtos )
    : Rtos::Task( rtos, 500/* stack size*/ )
    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update( void )
    {
      while(1)
      {
        cnt++;
        pause();  // pause the task until next time slot
      }
    }

  public:
    //---------------------------------------------------------------
    DWORD cnt;

}; //class myTask

//*******************************************************************
Rtos    rtos (    2,   // max num of tasks
               1000 ); // time slice in us

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

