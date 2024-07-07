#pragma once

#include "logic/SOController.h"


namespace so {
	namespace ManualStates {
		SOState turnLeft();
		SOState turnRight();
		SOState halt();

		SOState raiseArm();
		SOState lowerArm();


		/** Raises or lowers the arm and switches the pad on or off 
		* depending on the position of the arm
		*/
		SOState toggleArm();
	}
}
