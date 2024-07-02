#pragma once

#include "EmbSysLib.h"

namespace so {

	// Used for ColorSensor & PressureSensor
	class AnalogPart {
	public:

		AnalogPart(EmbSysLib::Hw::Adc_Mcu& adc, int channel)
		: m_adc(adc)
		, m_channel(channel)
		{
			adc.enable(m_channel);
		}


		virtual int getValue() const;

	private:
		EmbSysLib::Hw::Adc_Mcu& m_adc;
		int m_channel;
	};
}

