#include "ADC.h"
#include "Macros.h"

/*******************************************************************************
 *                      Private Function Prototypes                            *
 *******************************************************************************/
static Adc_StatusType Adc_ConvStateGet(void);


/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
	// Clear the ADC Registers before applying the configuration
	*ADC_MUX_REG = 0x00U;
	*ADC_CTRL_STATUS_REG_A = 0x00U;
	*ADC_SPECIAL_FUNC_IO_REG &= 0x1FU;
	
	// Apply the configuration of the desired ADC Group
	switch(ConfigPtr->AdcGroup)
	{
		case ADC_GROUP_0:
			// Set the Conversion mode/Trigger Source of the ADC Group
			switch (ConfigPtr->ConvMode)
			{
				case ADC_CONV_MODE_ONESHOT:
					CLEAR_BIT(*ADC_CTRL_STATUS_REG_A, ADC_AUTO_TRIGGER_ENABLE_BIT);
					break;
				case ADC_CONV_MODE_CONTINUOUS:
					SET_BIT(*ADC_CTRL_STATUS_REG_A, ADC_AUTO_TRIGGER_ENABLE_BIT);
					*ADC_SPECIAL_FUNC_IO_REG |= ADC_CONV_MODE_CONTINUOUS;
					break;
				case ADC_CONV_MODE_TRIGGER:
					SET_BIT(*ADC_CTRL_STATUS_REG_A, ADC_AUTO_TRIGGER_ENABLE_BIT);
					*ADC_SPECIAL_FUNC_IO_REG |= (ConfigPtr->TriggerSource);
					break;
				default:
					break;
			}
			
			// Set the voltage reference for the ADC Group
			*ADC_MUX_REG |= ConfigPtr->VoltRef;
			
			// Check the ADC Resolution, and in order to Work with 8-Bit Precision The Data Must Be Left Adjusted
			switch (ConfigPtr->Resolution)
			{
				case ADC_EIGHT_BIT:
					// Align the result left
					*ADC_MUX_REG |= ADC_ALIGN_LEFT;
					break;
				case ADC_TEN_BIT:
					// Align the result as Configured
					*ADC_MUX_REG |= ConfigPtr->ResultAlignment;
					break;
				default:
					break;
			}
			
			// Set the Clock division and Interrupt state for the ADC Group	
			*ADC_CTRL_STATUS_REG_A |= ConfigPtr->AdcPrescale;
			*ADC_CTRL_STATUS_REG_A |= ConfigPtr->IntState;
		
			break;
		default:
			break;
	}
	// Enable ADC unit by setting the ADEN bit
	SET_BIT(*ADC_CTRL_STATUS_REG_A, ADC_ENABLE_BIT);
}


void Adc_StartGroupConversion(Adc_GroupType Group)
{
	// Start conversion of the specified ADC Group
	switch(Group)
	{
		case ADC_GROUP_0:
			SET_BIT(*ADC_CTRL_STATUS_REG_A, ADC_START_CONVERSION_BIT);
			break;
		default:
			break;
	}
}


void Adc_StopGroupConversion(Adc_GroupType Group)
{
	// Stop conversion of the specified ADC Group
	switch(Group)
	{
		case ADC_GROUP_0:
			CLEAR_BIT(*ADC_CTRL_STATUS_REG_A, ADC_START_CONVERSION_BIT);
			break;
		default:
			break;
	}
}


void Adc_ReadChannel(const Adc_ConfigType *ConfigPtr, Adc_ValueType *DataBufferPtr)
{
	switch(ConfigPtr->AdcGroup)
	{
		case ADC_GROUP_0:
			// Clear the channel selection bits in the ADMUX register 
			*ADC_MUX_REG &= 0xE0U;
			// Select the required channel to read the result from it 
			*ADC_MUX_REG |= ConfigPtr->ChannelNumber;
		
			while(Adc_ConvStateGet() == ADC_BUSY )
			{
				/* Do Nothing */
			}
		
			switch(ConfigPtr->Resolution)
			{
				case ADC_EIGHT_BIT:
					*DataBufferPtr = *ADC_DATA_HIGH_REG;
					break;
				case ADC_TEN_BIT:
					switch(ConfigPtr->ResultAlignment)
					{
						case ADC_ALIGN_LEFT:
							*DataBufferPtr = (uint16)((*(uint16*)ADC_DATA_LOW_REG>>6U));
							break;
						case ADC_ALIGN_RIGHT:
							*DataBufferPtr = *(uint16*)ADC_DATA_LOW_REG;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
				break;
			default:
				break;
	}
	// Interrupt flag cleared by putting logic one on it 
	SET_BIT(*ADC_CTRL_STATUS_REG_A, ADC_INTERRUPT_FLAG_BIT);
}


static Adc_StatusType Adc_ConvStateGet(void)
{
	Adc_StatusType eLocalAdcState = ADC_BUSY;
	if(READ_BIT(*ADC_CTRL_STATUS_REG_A, ADC_INTERRUPT_FLAG_BIT))
	{
		eLocalAdcState = ADC_COMPLETED;
	}
	else
	{
		// Do Nothing
	}
	return (eLocalAdcState);
}