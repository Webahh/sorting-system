#pragma once
#include "SOControllerBase.h"
#include "Menu.h"

#include <memory>

namespace so {

    class SOController;
    class PressureController;
    class Crane;
    class ColorSensor;
    class DigitalPart;

    enum SortMode{
    	OFF,
		MANUAL,
		AUTO,
    };

    class App : public EmbSysLib::Dev::TaskManager::Task {
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

        void handleEvents();

        bool isValid() const;

        SortMode getSortMode() const;
        SOController* getSOController() const;
        PressureController* getPressureController() const;
        Crane* getCrane() const;
        ColorSensor* getColorSensor() const;
        DigitalPart* getLightBarrier() const;
        Menu* getMenu() const;


    private:
        SortMode m_sortMode;
        SOController* m_soController;
        PressureController* m_pressureController;
        Crane* m_crane; 
        ColorSensor* m_colorSensor;
        DigitalPart* m_lightBarrier;
        Menu* m_menu;
    };
}
