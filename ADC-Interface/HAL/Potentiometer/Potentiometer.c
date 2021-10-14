#include "Potentiometer.h"


void Pot_Init(void)
{
	Adc_Init(&gPotAdc_Configuration);
}


uint16 Pot_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	// uint16 u16LocalAdcResult = 0U;
	/*uint16 u16LocalAdcPrecision = 0U;
	switch(gPotAdc_Configuration.Resolution)
	{
		case ADC_EIGHT_BIT:
		u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
		break;
		case ADC_TEN_BIT:
		u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
		break;
		default:
		break;
	}*/
	Adc_StartGroupConversion(gPotAdc_Configuration.AdcGroup);
	Adc_ReadChannel(&gPotAdc_Configuration, &u16LocalAdcReading);
	// u16LocalAdcResult = ((u16LocalAdcReading*5)/u16LocalAdcPrecision);
	return (u16LocalAdcReading);
}



void Pot_Stop_Conversion(void)
{
	Adc_StopGroupConversion(gPotAdc_Configuration.AdcGroup);
}