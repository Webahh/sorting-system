#pragma once

#include "EmbSysLib.h"

#include <sys/types.h>

namespace so {
    class SOTimer: public EmbSysLib::Dev::TaskManager::Task
    {
    public:
        static SOTimer& get()
        {
            static SOTimer instance; 
            return instance;
        }
        SOTimer() {}

    public:
        SOTimer(SOTimer const&)         = delete;
        void operator=(SOTimer const&)  = delete;
    public:

        virtual void init(EmbSysLib::Dev::TaskManager& taskManager){
            taskManager.add( this );
        }

        virtual void update( void )
        {
            m_time++;
        }

        u_int64_t getTime() const{
            return m_time;
        }

private:
    u_int64_t m_time;
    };
}    
