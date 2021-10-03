#include "util/delay.h"
#include "SSD.h"
#include "ATmega32A_Configuration.h"

int main(void)
{
	SSD_Init();
	while (1)
	{
		SSD_Number_Set(50);
	}
}

