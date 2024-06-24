#pragma once
#include "SOControllerBase.h"
namespace so {

    class SOController;
    class PressureController;
    class Crane;
    class ColorSensor;
    class DigitalPart;


    class App {
        public:
        static App& get()
        {
            static App instance; 
            return instance;
        }
        App() {}

    public:
        App(App const&)             = delete;
        void operator=(App const&)  = delete;
        
        void init();
        void update();
        void terminate();

        bool isValid() const;

        SOController* getSOController() const;
        PressureController* getPressureController() const;
        Crane* getCrane() const;
        ColorSensor* getColorSensor() const;
        DigitalPart* getLightBarrier() const;

    private:
        SOController* m_soController;
        PressureController* m_pressureController;
        Crane* m_crane; 
        ColorSensor* m_colorSensor;
        DigitalPart* m_lightBarrier;
    };
}
