#ifndef ADC_H_
#define ADC_H_


#include "ADC_Pcfg.h"
#include "Std_Types.h"


/****************************************************
*                  MODULE DATATYPE                  *
****************************************************/

// The following enum selects ADC group
typedef enum
{
	ADC_GROUP_0         // there is only one ADC module inside ATmega32A
}Adc_GroupType;


// The following enum selects the channel of ADC  
typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}Adc_ChannelType;


// The following enum define the different voltage reference modes in ADC 
/* Note That if The Vin Exceeded The VREF This will Result in a Code 
 	Equal to 0x3FF Or 0xFF Depending on Your Resolution */
typedef enum
{
	ADC_REF_EXT_AREF     = 0x00U,
	ADC_REF_AVCC         = 0x40u,
	ADC_REF_INT_2_56_V   = 0xC0U
}Adc_RefType;


/* In order to Work with 8-Bit Precision The Data Must Be Left Adjusted 
   then you should Read ADCH , ADLAR is Responsible for Adjusting 
   The Data to Right(0) or Left(1) */ 
typedef enum
{
	ADC_EIGHT_BIT,
	ADC_TEN_BIT
}Adc_ResolutionType;


// The following enumeration selects the conversion mode of the ADC
typedef enum
{
	ADC_CONV_MODE_CONTINUOUS  = 0x00U,       // Free Running Mode
	ADC_CONV_MODE_ONESHOT     = 0x01U,        
	ADC_CONV_MODE_TRIGGER     = 0x02U   
}Adc_GroupConvModeType;


// The following enum selects the trigger source of the ADC 
typedef enum
{
	ADC_FREE_RUNNING_MODE     = 0x00U,
	ADC_ANALOUG_COMPARATOR    = 0x20U,
	ADC_EXT_INTERRUPT0        = 0x40U,
	ADC_TIMER0_CMP_MATCH      = 0x60U,
	ADC_TIMER0_OVF            = 0x80U,
	ADCE_TIMER1_CMP_MATCH_B   = 0xA0U,
	ADC_TIMER1_OVF            = 0xC0U,
	ADC_TIMER1_CAPTURE_EVENT  = 0xE0U	
}Adc_TriggerSourceType;


// The following enum selects the alignment of the ADC result */
typedef enum
{
	ADC_ALIGN_LEFT    = 0x20U,
	ADC_ALIGN_RIGHT   = 0x00U
}Adc_ResultAlignmentType;


// The following enum selects the pre scaling value of the ADC */
typedef enum
{
	ADC_PRESCALE_2     = 0x01U,
	ADC_PRESCALE_4,
	ADC_PRESCALE_8,
	ADC_PRESCALE_16,
	ADC_PRESCALE_32,
	ADC_PRESCALE_64, 
	ADC_PRESCALE_128   
} Adc_PrescaleType;


// The following enum defines whether the ADC Interrupt enabled or disabled
typedef enum
{
	ADC_INTERRUPT_DISABLE      = 0x00U,
	ADC_INTERRUPT_ENABLE	   = 0x08U
}Adc_IntStateType;


// The following enum lists the status of the ADC Module */
typedef enum
{
	ADC_IDLE,
	ADC_BUSY,
	ADC_COMPLETED
}Adc_StatusType;


// Type definition of the ADC result value 
typedef uint16 Adc_ValueType;


// Data Structure that holds the ADC Module configuration and required for initializing the ADC Driver
typedef struct
{
	Adc_GroupType           AdcGroup;
	Adc_RefType				VoltRef;
	Adc_GroupConvModeType	ConvMode;
	Adc_PrescaleType		AdcPrescale;
	Adc_ResolutionType		Resolution;
	Adc_TriggerSourceType   TriggerSource;
	Adc_ResultAlignmentType ResultAlignment;
	Adc_IntStateType        IntState;
	Adc_ChannelType         ChannelNumber;
}Adc_ConfigType;



/****************************************************
*                FUNCTIONS PROTOTYPES               *
****************************************************/

void Adc_Init(const Adc_ConfigType* ConfigPtr);
void Adc_StartGroupConversion(Adc_GroupType Group);
void Adc_StopGroupConversion(Adc_GroupType Group);
void Adc_ReadChannel(const Adc_ConfigType* ConfigPtr, Adc_ValueType *DataBufferPtr);
 
 

/****************************************************
*                EXTERNAL VARIABLES                 *
****************************************************/

// Extern Lcfg structures to be used by ADC and other modules 
extern const Adc_ConfigType gTempAdc_Configuration;
extern const Adc_ConfigType gPotAdc_Configuration;



#endif /* ADC_H_ */