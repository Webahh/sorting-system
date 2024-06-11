#include "AnalogPart.h"
namespace so {

    int AnalogPart::getValue() const{
		return m_adc.get(m_port); 
    }
}
