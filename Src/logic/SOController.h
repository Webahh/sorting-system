#pragma once

#include "logic/Clock.h"
#include <cstddef>
#include <list>
#include <functional>

namespace so{

    /* 
    * Represents a function or method as a state and 
    * defines other important functionalities for the functioning of the state machine  
    */
    struct SOState{

        SOState() {}

        template<typename F>
        SOState(F func)
            : m_func(func)
        	, m_startTime(0)
			, m_delay(0)
        {
        }
        
        template<typename F>
		SOState(F func, DWORD delay)
			: m_func(func)
			, m_startTime(0)
			, m_delay(delay)
		{
		}

        SOState(std::nullptr_t)
            : m_func(nullptr)
        	, m_startTime(0)
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
        /* Wrapped function pointer */
        std::function<SOState()> m_func;

        /* Start time */
        LWORD m_startTime;

        /* Delay for calculating the execution time */
        DWORD m_delay;
    };

    /* 
     * Helper function for quickly creating states 
     * from general functions or methods that do not return SOStates 
     */
    template<typename F>
    static SOState buildState(F&& func, SOState&& exitState, DWORD delay = 0){
        return SOState(
            [=]() mutable {
                func();
                return exitState;
            }
        , delay);
	}

    /*
    * State machine which cycles through all the enqueued states using the update method. 
    * The execution process of the state machine runs as follows: 
    *
    *    1. The top state (index 0) from the list (m_stateList) is taken and executed
    *    2. The returned state is then placed back in the top position (index 0) in the list, ready for the next cycle
    *    3. If the returned state is a nullptr or invalid, it is not inserted into the list and the next (Index 1)state moves up.
    *    4 Next cycle: Step 1 is executed 
    */

    class SOController {
    public:

    	SOController()
    		: m_bPaused(false)
    	{

    	}

        /* 
        * Inserts a new start state into the state machine
        * The state is inserted at the end of the list 
        */
        virtual void run(const SOState& startState);

        /* Executes a cycle in the state machine*/
        virtual void update();

        /*
         * Pauses the execution of the state machine
         */
        virtual void pause();

        /*
         * Resumes the excution of the state machine 
         */
        virtual void resume();

        /*
         * Removes all states in the queue
         */
        virtual void reset();

        bool isPaused() const;

    private:
        std::list<SOState> m_stateList;
        bool m_bPaused;
    };
}
