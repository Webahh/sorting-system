#pragma once
#include "logic/SOController.h"
#include "ui/Menu.h"
#include <memory>

namespace so {

    class SOController;
    class PressureController;
    class Crane;
    class AnalogPart;
    class DigitalPart;

    enum SortMode{
        	OFF,
    		MANUAL,
    		AUTO,
        };

    class App : public EmbSysLib::Dev::TaskManager::Task{
        public:
        static App& get()
        {
            static App instance; 
            return instance;
        }

        App()
        : m_sortMode(SortMode::OFF)
        {}

    public:
        App(App const&)             = delete;
        void operator=(App const&)  = delete;
        
        virtual void init();
        virtual void update() override;
        virtual void terminate();

        bool isValid() const;

        SortMode getSortMode() const;
        SOController* getSOController() const;
        PressureController* getPressureController() const;
        Crane* getCrane() const;
        AnalogPart* getColorSensor() const;
        DigitalPart* getLightBarrier() const;
        Menu* getMenu() const;

    protected:
        void handleEvents();
        void handleEventNoSort();
        void handleEventAutoSort();
        void handleEventManualSort();

    private:
        SortMode m_sortMode;
        SOController* m_soController;
        PressureController* m_pressureController;
        Crane* m_crane; 
        AnalogPart* m_colorSensor;
        DigitalPart* m_lightBarrier;
        Menu* m_menu;
    };
}
