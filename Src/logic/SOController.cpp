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
        
        SOState& frontState = m_stateList.front();

        if(frontState.getStartTime() == 0){
        	frontState.resetStartTime();
		}

        const int64_t currentTime = SOClock::get().getTime();
        const int64_t execTime = frontState.getExecTime();

        if(currentTime - execTime < 0){
        	return;
        }

        SOState tmpState = frontState;
        m_stateList.pop_front();

        SOState newState = tmpState();

        if(!newState)
            return;

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
