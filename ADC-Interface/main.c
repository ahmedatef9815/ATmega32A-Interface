#include "ADC.h"
#include "LCD.h"
#include "TempSensor.h"
#include "util/delay.h"
#include "Potentiometer.h"
#include "SW.h"


int main(void)
{
	Pot_Init();
	TempSensor_Init();
	LCD_Init();
	Switch_Init(SW0_DIR_REG, SW_0);
	Switch_Init(SW1_DIR_REG, SW_1);
	uint8 u8TempReading = 0;
	uint16 u16PotReading = 0;
	while(1)
	{
		if(Switch_Get_State(SW0_INP_REG, SW_0))
		{
			while (1)
			{
				u8TempReading = TempSensor_ValueGet();
				LCD_Clear();
				LCD_Integer_Display(u8TempReading);
				LCD_String_Display("Celsius");
				_delay_ms(500);
				if(Switch_Get_State(SW1_INP_REG, SW_1))
				{
					TempSensor_Stop_Conversion();
					LCD_Clear();
					break;
				}
			}
		}
		
		if(Switch_Get_State(SW1_INP_REG, SW_1))
		{
			while (1)
			{
				u16PotReading = Pot_ValueGet();
				LCD_Clear();
				LCD_Integer_Display(u16PotReading);
				LCD_String_Display("Ohm");
				_delay_ms(500);
				if (Switch_Get_State(SW0_INP_REG, SW_0))
				{
					Pot_Stop_Conversion();
					LCD_Clear();
					break;
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	/*
	 TempSensor_Init();
	 LCD_Init();
	 uint8 u8TempReading = 0;
	 while (1)
	 {
		 u8TempReading = TempSensor_ValueGet();
		 LCD_Integer_Display(u8TempReading);
		 _delay_ms(500);
		 LCD_Clear();
	 }
	*/

	
	
	
	
	/* 
	Pot_Init();
	LCD_Init();
	uint16 u16PotReading = 0;
	
    while (1) 
    {
		u16PotReading = Pot_ValueGet();
		LCD_Integer_Display(u16PotReading);
		_delay_ms(500);
		LCD_Clear();
    }
	*/
}

