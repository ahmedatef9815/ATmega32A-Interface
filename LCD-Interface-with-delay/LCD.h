#include "ATmega32A_Configuration.h"
#include "DIO.h"
#include "Std_Types.h"

#ifndef LCD_H_
#define LCD_H_

//Hardware connections
#define LCD_RS (DIO_PIN1)
#define LCD_RW (DIO_PIN2)
#define LCD_EN (DIO_PIN3)

#define LCD_CTRL_DIR_REG (PORTB_DIR_REG)
#define LCD_CTRL_OUT_REG (PORTB_OUT_REG)

#define LCD_DATA_DIR_REG (PORTA_DIR_REG)
#define LCD_DATA_OUT_REG (PORTA_OUT_REG)

//Initialization settings
#define LCD_CURSOR          (0U)          // 1 to Enable, 0 to Disable
#define LCD_BLINK           (0U)          // 1 to Enable, 0 to Disable
#define LCD_EIGHT_BIT_DATA  (0U)          // 1 to Enable, 0 for 4 bit
#define LCD_5x10_DOT        (0U)          // 1 to Enable, 0 for 5x8 dot
#define LCD_TWO_FOUR_LINES  (1U)          // 1 to Enable 2 lines(in case of 16x2) or 4 lines(in case of 16x4), 0 to Enable 1 line(in case of 16x2) or 2 lines(in case of 16x4) 

#define LCD_SHIFT_LEFT      (1U)
#define LCD_SHIFT_RIGHT     (0U)

// Generating an error if the user selected to work with two/four line and 5x10 dot
#if (LCD_TWO_FOUR_LINES && LCD_5x10_DOT)
#pragma GCC error "You can not have two/four lines LCD with 5x10 dot"
#endif



// List of command codes
#define LCD_CLEAR_DISPLAY           (0x01U)
#define LCD_RETURN_HOME             (0x02U)
#define LCD_DISPLAY_OFF             (0x08U)
#define LCD_DISPLAY_ON              (0x0CU | (LCD_CURSOR << 1U) | (LCD_BLINK))
#define LCD_CURSOR_SHIFT_RIGHT      (0x14U)
#define LCD_CURSOR_SHIFT_LEFT       (0x10U)
#define LCD_DISPLAY_SHIFT_RIGHT     (0x1CU)
#define LCD_DISPLAY_SHIFT_LEFT      (0x18U)
#define LCD_FUNCTION_SET            (0x20U | (LCD_EIGHT_BIT_DATA << 4U) | (LCD_TWO_FOUR_LINES << 3U) | (LCD_5x10_DOT << 2U))
#define LCD_DDRAM_CONST             (0x80U)

#define LCD_1ST_LINE_BASE           (0x00U)
#define LCD_2ND_LINE_BASE           (0x40U)
#define LCD_3RD_LINE_BASE           (0x10U)
#define LCD_4TH_LINE_BASE           (0x50U)

#define LCD_SHIFT(DIRECTION) ((DIRECTION == LCD_SHIFT_LEFT) ? LCD_Send_Instruction(LCD_DISPLAY_SHIFT_LEFT) : LCD_Send_Instruction(LCD_DISPLAY_SHIFT_RIGHT));
#define LCD_CURSOR_SHIFT(DIRECTION) ((DIRECTION == LCD_SHIFT_LEFT) ? LCD_Send_Instruction(LCD_CURSOR_SHIFT_LEFT) : LCD_Send_Instruction(LCD_CURSOR_SHIFT_RIGHT));

// List of LCD APIs
void LCD_Init(void);
void LCD_Send_Instruction(uint8 instruction);
void LCD_Clear(void);
void LCD_RowCol_Select(uint8 row, uint8 col);
void LCD_Char_Display(uint8 data);
void LCD_String_Display(char* string);
void LCD_Integer_Display(sint32 data);


#endif /* LCD_H_ */