#pragma once

#include "Timer.h"

#include <cstddef>
#include <list>

namespace so{

    struct SOState{
        typedef SOState(*StateFunc)();

        SOState() {}

        SOState(StateFunc func)
            : m_func(func)
        {
        }
        
        SOState(StateFunc func, float delay)
            : m_func(func)
            , m_startTime(SOTimer::get().getTime() + delay)
        {
        }
        
        SOState(std::nullptr_t)
            : m_func(nullptr)
        {
        }

        float getStartTime() const{
            return m_startTime;
        }

        SOState operator()() const{
            return m_func();
        }

        operator bool() const{
            return m_func != nullptr;
        }

    private:
        StateFunc m_func;
        float m_startTime;
    };

    class SOController {
    public:
        virtual void run(const SOState& startState);
        virtual void update();
        virtual void reset();

    private:
        std::list<SOState> m_stateList;
    };
}
