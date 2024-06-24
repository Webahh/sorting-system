#include "config.h"

EmbSysLib::Hw::PinConfig::MAP EmbSysLib::Hw::PinConfig::table[] =
	{
	  // SPI
	  SPI2_MOSI_PB15,
	  SPI2_MISO_PB14,
	  SPI2_SCK_PB13,
	  SPI2_NSS_PB12,

	  // UART
	  USART1_TX_PA9,
	  USART1_RX_PA10,

	  // ADC
	  ADC12_IN2_PA2,
	  ADC12_IN6_PA6,

	  END_OF_TABLE
	};

