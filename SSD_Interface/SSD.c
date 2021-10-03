#include "DIO.h"
#include "SSD.h"
#include "util/delay.h"

const uint8 gau8SSD_arr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	

void SSD_Init()
{
	//Make Seven Segment Enable Pins in OUTPUT Mode 
	Dio_ChannelDirectionSet(SSD_CTRL_DIR_REG, SSD1_EN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(SSD_CTRL_DIR_REG, SSD2_EN, DIO_OUTPUT);
	
	//Make Seven Segment Data Pins in OUTPUT Mode 
	*SSD_DATA_DIR_REG = 0xF0U;
}


void SSD_Number_Display(SSDLedsEnum_t num, uint8 ssd_no)
{
	switch(ssd_no)
	{
		case SSD1_EN:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_HIGH);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_LOW);
			break;
		case SSD2_EN:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_LOW);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_HIGH);
			break;
		default:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_LOW);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_LOW);
			break;
	}
	
	//This line zero the 4-bits of the data before setting the new value
	*SSD_DATA_OUT_REG &=~ (0xF0U); 
	if (SSD_TYPE == SSD_COMMON_CATHODE)
	{
		*SSD_DATA_OUT_REG |= (num & 0xF0U);
	}
	else if(SSD_TYPE == SSD_COMMON_ANODE)
	{
		*SSD_DATA_OUT_REG |= (~num & 0xF0U);
	}
}


//This function to display two numbers on two SSDs 
//actually I can not display one both at the same time so I will use delay
void SSD_Number_Set(uint16 number)
{
	SSD_Number_Display(gau8SSD_arr[(number%100)/10], SSD2_EN);
	_delay_ms(10);
	SSD_Number_Display(gau8SSD_arr[number%10], SSD1_EN);
	_delay_ms(10);
}
