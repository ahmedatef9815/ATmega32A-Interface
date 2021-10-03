#include "ATmega32A_Configuration.h"
#include "DIO.h"
#include "Std_Types.h"


#ifndef SSD_H_
#define SSD_H_

#define SSD_DATA_DIR_REG   (PORTA_DIR_REG)
#define SSD_DATA_OUT_REG   (PORTA_OUT_REG)
#define SSD_CTRL_DIR_REG   (PORTB_DIR_REG)
#define SSD_CTRL_OUT_REG   (PORTB_OUT_REG)

#define SSD1_EN            (DIO_PIN1)
#define SSD2_EN            (DIO_PIN2)

#define SSD_TYPE           (SSD_COMMON_CATHODE)

typedef enum
{
	SSD_COMMON_CATHODE,
	SSD_COMMON_ANODE
}SSDTypeEnum_t;

typedef enum
{
	ZERO  = 0x00U,
	ONE   = 0x10U,
	TWO   = 0x20U,
	THREE = 0x30U,
	FOUR  = 0x40U,
	FIVE  = 0x50U,
	SIX   = 0x60U,
	SEVEN = 0x70U,
	EIGHT = 0x80U,
	NINE  = 0x90
}SSDLedsEnum_t;


void SSD_Init();
void SSD_Number_Display(SSDLedsEnum_t num, uint8 ssd_no);
void SSD_Number_Set(uint16 number);

extern const uint8 gau8SSD_arr[10];


#endif /* SSD_H_ */