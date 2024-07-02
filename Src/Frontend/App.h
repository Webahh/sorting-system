#pragma once
#include "EventReceiver.h"
#include "SOControllerBase.h"
#include "Screen.h"
#include "Display.h"
#include "Menu.h"

#include <memory>

namespace so {

    class SOController;
    class PressureController;
    class Crane;
    class ColorSensor;
    class DigitalPart;

    class App : public EmbSysLib::Dev::TaskManager::Task, public EventReceiver {
        public:
        static App& get()
        {
            static App instance; 
            return instance;
        }

        App()
        {
        	setupMappings(
        			{

        			}
        	);
        }

    public:
        App(App const&)             = delete;
        void operator=(App const&)  = delete;
        
        virtual void init();
        virtual void update() override;
        virtual bool forwardEvent(const EventType& eventType) override;
        virtual void terminate();

        void handleEvents();

        bool isValid() const;

        SOController* getSOController() const;
        PressureController* getPressureController() const;
        Crane* getCrane() const;
        ColorSensor* getColorSensor() const;
        DigitalPart* getLightBarrier() const;
        Screen* getScreen() const;


    private:
        SOController* m_soController;
        PressureController* m_pressureController;
        Crane* m_crane; 
        ColorSensor* m_colorSensor;
        DigitalPart* m_lightBarrier;
        Screen* m_screen;
    };
}
