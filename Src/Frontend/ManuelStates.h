#pragma once

#include "SOControllerBase.h"

#include "App.h"
#include "Crane.h"

namespace so {

   SOState turnLeft(); 
   SOState turnRight(); 
   SOState halt(); 
   
   SOState raiseArm(); 
   SOState lowerArm(); 
   
   SOState enablePad(); 
   SOState disablePad(); 
}