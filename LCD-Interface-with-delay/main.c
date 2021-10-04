#include "LCD.h"
#include "ATmega32A_Configuration.h"
#include "util/delay.h"

int main(void)
{
	LCD_Init();
    while (1) 
    {
		LCD_SHIFT(LCD_SHIFT_LEFT);
		LCD_RowCol_Select(0, 5);
		LCD_String_Display("3atef");
		LCD_RowCol_Select(1, 0);
		LCD_String_Display("World");
		LCD_Integer_Display(101);
    }
}

