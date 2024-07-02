#pragma once

#include "SOControllerBase.h"
#include <cstddef>

namespace so {
	namespace AutoStates {


   SOState stateDropItem();
   SOState stateMoveToDropperGarbage();
   SOState stateMoveToDropperLeft();
   SOState stateMoveToDropperMiddle();
   SOState stateMoveToDropperRight();
   SOState stateCheckColor();
   SOState stateMoveToColorSensor();
   SOState stateCollectItem();
   SOState stateCheckItemExists();
   SOState stateMoveToLoader();

   void stateBeginAutoMovement();
   void stateLeaveAutoMovement();
	}
}
