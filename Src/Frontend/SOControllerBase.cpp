#include "SOControllerBase.h"

namespace so {

    void SOController::run(const SOState& startState){
        if(!startState){
            return;
        }

        m_stateList.push_back(startState);
    }

    void SOController::update() {
        if(m_stateList.empty()){
           return;
        }
        
        const int64_t currentTime = SOClock::get().getTime();
        const int64_t stateTime = m_stateList.front().getStartTime();

        if(currentTime - stateTime < 0){
        	return;
        }

        SOState state = m_stateList.front();
        m_stateList.pop_front();

        SOState newState = state();

        if(!newState)
            return;

        m_stateList.push_front(newState);
    }

    void SOController::reset(){
       m_stateList.clear(); 
    }
}
