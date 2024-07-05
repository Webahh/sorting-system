#include "logic/AutoStates.h"
#include "ui/App.h"
#include "movement/Crane.h"
#include "movement/PressureController.h"
#include "sensoric/AnalogPart.h"
#include "sensoric/DigitalPart.h"


namespace so {

namespace AutoStates {

		bool bMoveToGarbage = false;
		int itemCount = 0;
		std::string lastDetectedColor;

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

		  if(!bMoveToGarbage){
			  itemCount++;
		  }

		  setIsMoveToGarbage(false);

		  con.run(buildState([](){ App::get().getCrane()->lowerArm();}, nullptr, 25));
		  con.run(buildState([](){ App::get().getCrane()->disablePad();}, nullptr, 30));
		  con.run(buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToLoader, 10), 30));

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

		  static const int limitWhiteRed = 40000;
		  static const int limitRedBlue = 50000;

		  if(app.getColorSensor()->getValue() < limitWhiteRed){
			 lastDetectedColor = "White";
			 return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperMiddle, 25));
		  }
		  else if(app.getColorSensor()->getValue() > limitWhiteRed && app.getColorSensor()->getValue() < limitRedBlue){
			  lastDetectedColor = "Red";
			  return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperLeft, 25));
		  }
		  else if(app.getColorSensor()->getValue() > limitRedBlue){
			  lastDetectedColor = "Blue";
			  return buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToDropperRight, 25));
		  }

		  return SOState(stateCheckColor);
	   }

	   SOState stateMoveToColorSensor(){
		  static const int colorSensorPosition = 7;

		  return moveToPosition(
				  stateMoveToColorSensor,
				  bMoveToGarbage ? SOState(stateMoveToDropperGarbage) : buildState([](){App::get().getCrane()->lowerArm();}, SOState(stateCheckColor, 25), 25),
				  colorSensorPosition);
	   }

	   SOState stateCollectItem() {
		  App& app = App::get();
		  SOController& con = *app.getSOController();

		  con.run(buildState([](){ App::get().getCrane()->lowerArm();}, nullptr, 50));
		  con.run(buildState([](){ App::get().getCrane()->enablePad();}, nullptr, 50));
		  con.run(buildState([](){ App::get().getCrane()->raiseArm();}, SOState(stateMoveToColorSensor, 20), 50));

		  return nullptr;
	   }

	   SOState stateCheckItemExists(){
		  App& app = App::get();
		  if(app.getLightBarrier()->getState()){
			  app.getPressureController()->enable();
			 return SOState(stateCollectItem);
		  }

		  itemCount = 0;

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
			 app.getCrane()->raiseArm();
			 app.getCrane()->disablePad();
			 app.getCrane()->turnLeft();
		  }

		  return SOState(stateMoveToLoader);
	   }

	   int getItemCount(){
		   return itemCount;
	   }

	   void setItemCount(int count){
		   itemCount = count;
	   }

	   const std::string& getLastDetectedColor(){
		   return lastDetectedColor;
	   }

	   bool getIsMoveToGarbage(){
		   return bMoveToGarbage;
	   }

	   void setIsMoveToGarbage(bool bGarbage){
		   bMoveToGarbage = bGarbage;
	   }
	}
}
