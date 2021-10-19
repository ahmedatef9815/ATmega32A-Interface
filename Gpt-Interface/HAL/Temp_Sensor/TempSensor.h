#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "ADC.h"

#define TEMP_SENSOR_PIN   (ADC_CHANNEL_0)

#define ADC_TEN_BIT_PRECISION     (1023U)
#define ADC_EIGHT_BIT_PRECISION   (255U)
#define ADC_5_V_REF               (5.0)
#define ADC_3_3_V_REF             (3.3)


void TempSensor_Init(void);
uint8 TempSensor_ValueGet(void);  
void TempSensor_Stop_Conversion(void);


#endif /* TEMPSENSOR_H_ */