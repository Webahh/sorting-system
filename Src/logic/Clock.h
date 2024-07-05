#pragma once

#include "EmbSysLib.h"
#include <sys/types.h>

namespace so {
    class SOClock : public EmbSysLib::Dev::TaskManager::Task
    {
    public:
        static SOClock& get()
        {
            static SOClock instance; 
            return instance;
        }
        SOClock()
        {
        }

    public:
        SOClock(SOClock const&)         = delete;
        void operator=(SOClock const&)  = delete;
    public:

        virtual void update( void )
        {
            m_time++;
        }

        LWORD getTime() const{
            return m_time;
        }

    private:
        LWORD m_time;
    };
}    
