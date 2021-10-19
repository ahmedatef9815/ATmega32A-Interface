#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_


#include "ADC.h"

#define POTENTIOMETER_PIN   (ADC_CHANNEL_1)

#define ADC_TEN_BIT_PRECISION     (1023U)
#define ADC_EIGHT_BIT_PRECISION   (255U)
#define ADC_5_V_REF               (5.0)
#define ADC_3_3_V_REF             (3.3)


void Pot_Init(void);
uint16 Pot_ValueGet(void);
void Pot_Stop_Conversion(void);



#endif /* POTENTIOMETER_H_ */