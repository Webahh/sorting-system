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

        SOState state = m_stateList.front();
        m_stateList.pop_front();
        m_stateList.push_front(state());
    }
}