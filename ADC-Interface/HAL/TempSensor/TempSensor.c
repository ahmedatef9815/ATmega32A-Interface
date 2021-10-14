#include "TempSensor.h"


void TempSensor_Init(void)
{
	Adc_Init(&gTempAdc_Configuration);
}


uint8 TempSensor_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	uint16 u16LocalAdcPrecision = 0U;
	uint8 u8LocalTemp = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel(&gTempAdc_Configuration, &u16LocalAdcReading);
	switch(gTempAdc_Configuration.Resolution)
	{
		case ADC_EIGHT_BIT:
			u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
			break;
		case ADC_TEN_BIT:
			u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
			break;
		default:
			break;
	}
	// Temperature Sensor equation
	u8LocalTemp = (((u16LocalAdcReading * ADC_5_V_REF * 100) / u16LocalAdcPrecision)); 
	return (u8LocalTemp);
}



void TempSensor_Stop_Conversion(void)
{
	Adc_StopGroupConversion(gTempAdc_Configuration.AdcGroup);
}