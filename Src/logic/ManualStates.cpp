#include "logic/ManualStates.h"
#include "movement/Crane.h"
#include "ui/App.h"

namespace so {

	namespace ManualStates{

		// helper function to turn the crane
		template<typename F>
		SOState turn(const SOState& startState, MotorDirection direction, F&& func){		   
			
			App& app = App::get();

			// saves the start position so that the end position can be determined 
			static int pos = -1;

			// clear all other requests
			app.getSOController()->reset();

			// Checks whether the crane is already moving in the desired direction
			if(app.getCrane()->getMotor().getDirection() != direction){
				if(pos == -1)
					pos = app.getCrane()->getPosition();

				// Executes the function to move the crane
				func();
			}
			// Checks whether the crane has already moved by one position 	
			else if(std::abs(app.getCrane()->getPosition() - pos) > 0 ||
					(app.getCrane()->getMotor().getDirection() !=  MotorDirection::RIGHT_TURN && app.getCrane()->getEndswitch().getState())){
				pos = -1;
				app.getCrane()->halt();
				return nullptr;
			}

			// repeat current state
			return startState;
		}

		bool bManualState = false;

		SOState turnLeft(){
			return turn(SOState(turnLeft), MotorDirection::LEFT_TURN, [](){App::get().getCrane()->turnLeft();});
		}

		SOState turnRight(){
			return turn(SOState(turnRight), MotorDirection::RIGHT_TURN, [](){App::get().getCrane()->turnRight();});
		}

		SOState toggleArm(){

			if(App::get().getCrane()->getArmVent().isOpen()) {
				App::get().getCrane()->raiseArm();
				return nullptr;
			}else{
				App::get().getCrane()->lowerArm();

				if(!App::get().getCrane()->getPadVent().isOpen()){
					return buildState([](){ App::get().getCrane()->enablePad();}, nullptr, 150);
				}else{
					return buildState([](){ App::get().getCrane()->disablePad();}, nullptr, 100);
				}
			}
		}
	}
}
