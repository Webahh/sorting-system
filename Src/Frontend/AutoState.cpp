#include "AutoStates.h"
#include "App.h"
#include "Backend/Crane.h"
#include "Backend/AnalogPart.h"
#include "Backend/DigitalPart.h"
#include "Backend/PressureController.h"

namespace so {

namespace AutoStates {
		static SOState moveToPosition(const SOState& startFunc, const SOState& exitFunc, int pos){

			App& app = App::get();
			Crane& crane = *app.getCrane();
			const Motor& motor = crane.getMotor();

			if(crane.getPosition() == pos){
				crane.halt();
				return exitFunc;
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

		  con.run(buildState([](){ App::get().getCrane()->lowerArm();}, nullptr, 10));
		  con.run(buildState([](){ App::get().getCrane()->disablePad();}, nullptr, 50));
		  con.run(buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToLoader, 10), 80));

		  return nullptr;
	   }

	   SOState stateMoveToDropperGarbage(){
		  static const int garbageDropperPosition = 18;
		  return moveToPosition(stateMoveToDropperGarbage, stateDropItem, garbageDropperPosition);
	   }

	   SOState stateMoveToDropperLeft(){
		  static const int leftDropperPosition = 10;
		  return moveToPosition(stateMoveToDropperLeft, stateDropItem, leftDropperPosition);
	   }

	   SOState stateMoveToDropperMiddle(){
		  static const int middleDropperPosition = 12;
		  return moveToPosition(stateMoveToDropperMiddle, stateDropItem, middleDropperPosition);
	   }

	   SOState stateMoveToDropperRight(){
		  static const int rightDropperPosition = 14;
		  return moveToPosition(stateMoveToDropperRight, stateDropItem, rightDropperPosition);
	   }

	   SOState stateCheckColor(){
		  App& app = App::get();

		  static const int limitRedWhite = 40000;
		  static const int limitWhiteBlue = 50000;

		  if(app.getColorSensor()->getValue() < limitRedWhite){
			 return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperMiddle, 25));
		  }
		  else if(app.getColorSensor()->getValue() > limitRedWhite && app.getColorSensor()->getValue() < limitWhiteBlue){
			  return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperLeft, 25));
		  }
		  else if(app.getColorSensor()->getValue() > limitWhiteBlue){
			  return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperRight, 25));
		  }

		  return SOState(stateCheckColor);
	   }

	   SOState stateMoveToColorSensor(){
		  static const int colorSensorPosition = 7;

		  return moveToPosition(
				  stateMoveToColorSensor,
				  buildState([](){App::get().getCrane()->lowerArm();}, SOState(stateCheckColor, 25), 25),
				  colorSensorPosition);
	   }

	   SOState stateCollectItem() {
		  App& app = App::get();
		  SOController& con = *app.getSOController();

		  con.run(buildState([](){ App::get().getCrane()->lowerArm();}, nullptr, 10));
		  con.run(buildState([](){ App::get().getCrane()->enablePad();}, nullptr, 50));
		  con.run(buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToColorSensor, 25), 80));

		  return nullptr;
	   }

	   SOState stateCheckItemExists(){
		  App& app = App::get();
		  if(app.getLightBarrier()->getState()){
			  app.getPressureController()->enable();
			 return SOState(stateCollectItem);
		  }
		  app.getPressureController()->disable();
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
}
