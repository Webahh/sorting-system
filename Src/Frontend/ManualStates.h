#pragma once

#include "SOControllerBase.h"


namespace so {

   SOState turnLeft(); 
   SOState turnRight(); 
   SOState halt(); 
   
   SOState raiseArm(); 
   SOState lowerArm(); 
   SOState toggleArm();

   
   SOState enablePad(); 
   SOState disablePad(); 
}
