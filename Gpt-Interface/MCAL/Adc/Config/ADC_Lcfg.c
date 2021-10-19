#include "ADC.h"


const Adc_ConfigType gTempAdc_Configuration =
{
	ADC_GROUP_0,
	ADC_REF_AVCC,
	ADC_CONV_MODE_ONESHOT,
	ADC_PRESCALE_128,
	ADC_TEN_BIT,
	0U,         // No Trigger source
	ADC_ALIGN_LEFT,
	ADC_INTERRUPT_DISABLE,
	ADC_CHANNEL_0
};



const Adc_ConfigType gPotAdc_Configuration =
{
	ADC_GROUP_0,
	ADC_REF_AVCC,
	ADC_CONV_MODE_ONESHOT,
	ADC_PRESCALE_128,
	ADC_TEN_BIT,
	0U,         // No Trigger source
	ADC_ALIGN_LEFT,
	ADC_INTERRUPT_DISABLE,
	ADC_CHANNEL_1
};