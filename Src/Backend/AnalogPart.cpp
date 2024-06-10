#include "AnalogPart.h"
namespace so {

    int AnalogPart::getValue(){
		return m_adc.get(m_port); 
    }
}