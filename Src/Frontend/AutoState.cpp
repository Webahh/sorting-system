#include "AutoStates.h"
#include "App.h"
#include "Crane.h"
#include "Backend/ColorSensor.h"
#include "Backend/DigitalPart.h"

namespace so {

    template<SOState::StateFunc startFunc, SOState::StateFunc exitFunc>
    static SOState moveToPosition(int pos, u_int64_t delay = 0){

        App& app = App::get();
        Crane& crane = *app.getCrane();
        const Motor& motor = crane.getMotor();

        if(crane.getPosition() == pos){
            crane.halt();
            return SOState(exitFunc, delay);
        } else if(crane.getPosition() < pos && motor.getDirection() != MotorDirection::RIGHT_TURN){
            crane.turnRight();
        } else if(crane.getPosition() > pos && motor.getDirection() != MotorDirection::LEFT_TURN) {
            crane.turnLeft();
        }

        return SOState(startFunc);
   }

   SOState stateDropItem(){

      App& app = App::get();
      SOController& con = *app.getSOController();

      con.run(SOState([](){
         App::get().getCrane()->lowerArm();
         return SOState(nullptr);
      }, 10));

      con.run(SOState([](){
         App::get().getCrane()->disablePad();
         return SOState(nullptr);
      }, 50));

      con.run(SOState([](){
         App::get().getCrane()->raiseArm();
         return SOState(stateMoveToLoader);
      }, 80));
      
      return nullptr; 
   }

   SOState stateMoveToDropperGarbage(){
      static const int garbageDropperPosition = 18;
      return moveToPosition<stateMoveToDropperGarbage, stateDropItem>(garbageDropperPosition);
   }

   SOState stateMoveToDropperLeft(){
      static const int leftDropperPosition = 10;
      return moveToPosition<stateMoveToDropperLeft, stateDropItem>(leftDropperPosition);
   }
    
   SOState stateMoveToDropperMiddle(){
      static const int middleDropperPosition = 12;
      return moveToPosition<stateMoveToDropperMiddle, stateDropItem>(middleDropperPosition);
   }

   SOState stateMoveToDropperRight(){
      static const int rightDropperPosition = 14;
      return moveToPosition<stateMoveToDropperRight, stateDropItem>(rightDropperPosition);
   }

   SOState stateCheckColor(){
      App& app = App::get();

      static const int colorWhite = 40000;
      static const int colorRedLow = 40000, colorRedHigh = 50000;
      static const int colorBlue = 50000;

      if(app.getColorSensor()->getValue() < colorWhite){
         return SOState([](){
             App::get().getCrane()->raiseArm();
             return SOState(stateMoveToDropperMiddle, 25);
         });
      }
      else if(app.getColorSensor()->getValue() > colorRedLow && app.getColorSensor()->getValue() < colorRedHigh){
    	  return SOState([](){
			   App::get().getCrane()->raiseArm();
			   return SOState(stateMoveToDropperLeft, 25);
		   });
      }
      else if(app.getColorSensor()->getValue() > colorBlue){
    	  return SOState([](){
			   App::get().getCrane()->raiseArm();
			   return SOState(stateMoveToDropperRight, 25);
		   });
      }

      return SOState(stateCheckColor);
   }

   SOState stateDrop(){
	   App::get().getCrane()->lowerArm();
	   return SOState(stateCheckColor, 25);
   }

   SOState stateMoveToColorSensor(){
      static const int colorSensorPosition = 7;
      return moveToPosition<stateMoveToColorSensor, stateDrop>(colorSensorPosition, 25);
   }

   SOState stateCollectItem() {
      App& app = App::get();
      SOController& con = *app.getSOController();

      con.run(SOState([](){
         App::get().getCrane()->lowerArm();
         return SOState(nullptr);
      }, 10));

      con.run(SOState([](){
         App::get().getCrane()->enablePad();
         return SOState(nullptr);
      }, 50));

      con.run(SOState([](){
         App::get().getCrane()->raiseArm();
         return SOState(stateMoveToColorSensor, 25);
      }, 80));
      
      return nullptr;
   }

   SOState stateCheckItemExists(){
      if(App::get().getLightBarrier()->getState()){
         return SOState(stateCollectItem);
      }      

      return SOState(stateCheckItemExists); 
   }

   SOState stateMoveToLoader(){

      App& app = App::get();

      if(app.getCrane()->getEndswitch().getState()){
         app.getCrane()->halt();
         return SOState(stateCheckItemExists);
      }
      else if(app.getCrane()->getMotor().getDirection() != MotorDirection::LEFT_TURN){
         app.getCrane()->turnLeft();
      }

      return SOState(stateMoveToLoader);
   }
}
