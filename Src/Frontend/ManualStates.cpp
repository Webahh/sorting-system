#include "ManualStates.h"
#include "Backend/Crane.h"
#include "App.h"

namespace so {

	template<typename F>
	SOState turn(const SOState& startState, MotorDirection direction,  F&& func){
		App& app = App::get();
		static int pos = -1;

			if(app.getCrane()->getMotor().getDirection() != direction){
				if(pos != 1)
					pos = app.getCrane()->getPosition();

				func();
			}else if(app.getCrane()->getPosition() == pos + 1){
				pos = -1;
				app.getCrane()->halt();
				return nullptr;
			}

			return startState;
	}


	SOState turnLeft(){
		return turn(SOState(turnLeft), MotorDirection::LEFT_TURN, [](){App::get().getCrane()->turnLeft();});
	}

	SOState turnRight(){
		return turn(SOState(turnRight), MotorDirection::RIGHT_TURN, [](){App::get().getCrane()->turnRight();});
	}

	SOState toggleArm(){

		if(App::get().getCrane()->getArmVent().isOpen()) {
			App::get().getCrane()->raiseArm();
		}else{
			App::get().getCrane()->lowerArm();
		}

		return nullptr;
	}
}
