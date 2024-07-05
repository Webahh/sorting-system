#pragma once

#include "logic/SOController.h"
#include <cstddef>
#include <string>

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

	   int getItemCount();
	   void setItemCount(int count);
	   const std::string& getLastDetectedColor();
	   bool getIsMoveToGarbage();
	   void setIsMoveToGarbage(bool bGarbage);
	}
}
