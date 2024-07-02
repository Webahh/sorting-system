#pragma once

#include "EmbSysLib.h"

namespace so {
//will inherit from Class Part
	class AnalogPart {
	public:

		//Con needs ref of Adc_Mcu Obj
		AnalogPart(EmbSysLib::Hw::Adc_Mcu& adc, int port)
		: m_adc(adc)
		, m_port(port)
		{
			adc.enable(m_port);
		}


		virtual int getValue() const;

	private:
		EmbSysLib::Hw::Adc_Mcu& m_adc;
		int m_port;
	};
}

