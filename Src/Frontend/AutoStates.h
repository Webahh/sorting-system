#pragma once

#include "SOControllerBase.h"
#include "App.h"
#include "Crane.h"

namespace so {

    

    inline SOState stateCheckElementExists(){
       return nullptr; 
    }

    inline SOState stateActionCheckColor(){
       return nullptr; 
    }

    inline SOState stateMoveToDropperLeft(){
       return nullptr; 
    }
    
    inline SOState stateMoveToDropperMiddle(){
       return nullptr; 
    }

    inline SOState stateMoveToDropperRight(){
       return nullptr; 
    }

    inline SOState stateMoveToDropperGarbage(){
       return nullptr; 
    }

    inline SOState stateDrop(){
       return nullptr; 
    }

    inline SOState stateMoveToLoader(){

        App& app = App::get();

        if(app.getCrane()->getEndswitch().getState()){
            return SOState(stateCheckElementExists);
        }

        return SOState(stateMoveToLoader());
    }
}
