#pragma once

#include <cstddef>
#include <list>

namespace so{
    
    struct SOState{
        typedef SOState(*StateFunc)();
        SOState(StateFunc func)
            : m_func(func)
        {
        }
        
        SOState(std::nullptr_t)
            : m_func(nullptr)
        {
        }

        SOState operator()() const{
            return m_func();
        }

        operator bool() const{
            return m_func != nullptr;
        }

    private:
        StateFunc m_func;
    };

    class SOController {
    public:
        virtual void run(const SOState& startState);
        virtual void update();

    private:
        std::list<SOState> m_stateList;
    };
}