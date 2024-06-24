#pragma once

#include "SOControllerBase.h"
#include <cstddef>

namespace so {

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
}
