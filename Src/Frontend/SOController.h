#pragma once

#include <Frontend/Clock.h>
#include <cstddef>
#include <list>
#include <functional>

namespace so{

    struct SOState{

        SOState() {}

        template<typename F>
        SOState(F func)
            : m_func(func)
        	, m_startTime(SOClock::get().getTime())
			, m_delay(0)
        {
        }
        
        template<typename F>
		SOState(F func, DWORD delay)
			: m_func(func)
			, m_startTime(SOClock::get().getTime())
			, m_delay(delay)
		{
		}

        SOState(std::nullptr_t)
            : m_func(nullptr)
        	, m_startTime(SOClock::get().getTime())
        			, m_delay(0)
        {
        }

        LWORD getStartTime() const{
            return m_startTime;
        }

        void resetStartTime() {
        	m_startTime = SOClock::get().getTime();
        }

        LWORD getDelay() const{
        	return m_startTime;
        }

        LWORD setDelay() const{
			return m_startTime;
		}

        LWORD getExecTime() const {
        	return m_startTime + m_delay;
        }

        SOState operator()() const{
            return m_func();
        }

        operator bool() const{
            return m_func != nullptr;
        }

    private:
        std::function<SOState()> m_func;
        LWORD m_startTime;
        DWORD m_delay;
    };

    template<typename F>
	static SOState buildState(F&& func, SOState&& exitState, DWORD delay = 0){
		return SOState([=]() mutable {
			func();
			exitState.resetStartTime();
			return exitState;
		}, delay);
	}

    class SOController {
    public:
        virtual void run(const SOState& startState);
        virtual void update();
        virtual void reset();

    private:
        std::list<SOState> m_stateList;
    };
}
