#include "logic/SOController.h"
#include "ui/App.h"
#include "movement/Crane.h"

namespace so {

    void SOController::run(const SOState& startState){
        if(!startState){
            return;
        }

        m_stateList.push_back(startState);
    }

    void SOController::update() {
        if(m_stateList.empty() || m_bPaused){
           return;
        }
        
        // Gets the first state
        SOState& frontState = m_stateList.front();

        // Initalize its start time once
        if(frontState.getStartTime() == 0){
        	frontState.resetStartTime();
		}

        // Checks whether enough time has already passed for the delay
        const int64_t currentTime = SOClock::get().getTime();
        const int64_t execTime = frontState.getExecTime();
        if(currentTime - execTime < 0){
        	return;
        }

        /* Copies the state to be executed, due to a possible change of 
        the state machine. For example, a call to the reset(...) method */
        SOState tmpState = frontState;
        m_stateList.pop_front();

        // Executes the state and saves the returned new state
        SOState newState = tmpState();

        if(!newState)
            return;

        // Inserts the returned state at the front of the list
        m_stateList.push_front(newState);
    }

    void SOController::pause(){
    	m_bPaused = true;
    }

    void SOController::resume(){
    	m_bPaused = false;
    }

    void SOController::reset(){
       m_stateList.clear(); 
    }

    bool SOController::isPaused() const{
    	return m_bPaused;
    }
}
