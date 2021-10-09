#include "LCD.h"
#include "util/delay.h"
#include "DIO.h"
#include "stdlib.h"


void LCD_Init(void)
{
	// Wait for more than 15 ms after VCC rises to 4.5V as LCD MC is slower than ATmega32A 
	_delay_ms(20U);
	// Set The Control Pins Direction to OUTPUT
	Dio_ChannelDirectionSet(LCD_CTRL_DIR_REG, LCD_RS, DIO_OUTPUT);
	Dio_ChannelDirectionSet(LCD_CTRL_DIR_REG, LCD_RW, DIO_OUTPUT);
	Dio_ChannelDirectionSet(LCD_CTRL_DIR_REG, LCD_EN, DIO_OUTPUT);
	
	#if LCD_EIGHT_BIT_DATA
	// Set the Direction of the 8 Data pins to OUTPUT
	*LCD_DATA_DIR_REG = 0XFFU;
	#else
	// Set the Direction of the Upper 4 Data pins to OUTPUT
	*LCD_DATA_DIR_REG |= (0XF0U);
	LCD_Send_Instruction(LCD_RETURN_HOME);
	#endif
	
	LCD_Send_Instruction(LCD_FUNCTION_SET);
	LCD_Send_Instruction(LCD_DISPLAY_ON);
	LCD_Send_Instruction(LCD_CLEAR_DISPLAY);
}

void LCD_Send_Instruction(uint8 instruction)
{
	// RW, RS Should be 0 when Writing instructions to LCD
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_RS, DIO_LOW);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_RW, DIO_LOW);
	// Delay of Address Set 60ns minimum
	_delay_ms(1);
	
	#if LCD_EIGHT_BIT_DATA
	// Enable LCD E=1
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	// Delay for processing PW min 450ns
	_delay_ms(1);
	Dio_PortWrite(LCD_DATA_OUT_REG, instruction);
	// Data set-up time delay  Tdsw = 195 ns
	_delay_ms(1);
	// Disable LCD E=0
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	// Data Hold delay Th = 10ns
	_delay_ms(1);
	
	#else
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	*LCD_DATA_OUT_REG &= 0x0F;            // BSFAR EL 4 BITS ELLY 3AL SHMAL EL UPPER Y3NE 3SHAN DOOL ELLY HN2EL 3LEEHOM ELDATA
	*LCD_DATA_OUT_REG |= (instruction & 0xF0U);
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	*LCD_DATA_OUT_REG &= 0X0FU;
	*LCD_DATA_OUT_REG |= (instruction << 4) & 0xF0U;
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	_delay_ms(1);
	
	#endif
}


void LCD_Clear(void)
{
	LCD_Send_Instruction(LCD_CLEAR_DISPLAY);
}


void LCD_RowCol_Select(uint8 row, uint8 col)
{
	uint8 u8LocalLineAddress = 0U;
	switch(row)
	{
		case 0:
			// When Writing To LCD 1st Col The Base Address is 0x00
			u8LocalLineAddress = col | LCD_1ST_LINE_BASE;
			break;
		case 1:
			u8LocalLineAddress = col | LCD_2ND_LINE_BASE;
			break;
		case 2:
			u8LocalLineAddress = col | LCD_3RD_LINE_BASE;
			break;
		case 3:
			u8LocalLineAddress = col | LCD_4TH_LINE_BASE;
			break;
		default:
			break;
	}
	LCD_Send_Instruction(LCD_DDRAM_CONST | u8LocalLineAddress);
}


void LCD_Char_Display(uint8 data)
{
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_RS, DIO_HIGH);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_RW, DIO_LOW);
	_delay_ms(1);
	
	#if LCD_EIGHT_BIT_DATA
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	Dio_PortWrite(LCD_DATA_OUT_REG, data);
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	_delay_ms(1);
	
	#else
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	*LCD_DATA_OUT_REG = 0x0FU;
	*LCD_DATA_OUT_REG |= (data & 0xF0U);
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	*LCD_DATA_OUT_REG = 0x0FU;
	*LCD_DATA_OUT_REG |= (data << 4) & 0xF0U;
	_delay_ms(1);
	Dio_ChannelWrite(LCD_CTRL_OUT_REG, LCD_EN, DIO_LOW);
	_delay_ms(1);
	
	#endif
}


void LCD_String_Display(char* string)
{
	while(*string != '\0')
	{
		LCD_Char_Display(*string);
		string++;
	}
}


void LCD_Integer_Display(sint32 data)
{
	// String to hold the ascii result
	char u8LocalResult[17];
	itoa(data, u8LocalResult, 10);
	LCD_String_Display(u8LocalResult);
}
