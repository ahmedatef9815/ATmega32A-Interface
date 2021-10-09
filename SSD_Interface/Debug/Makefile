################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../HAL/SSD \
../MCAL \
../HAL \
../MCAL/DIO \
../Utilities


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../HAL/SSD/SSD.c \
../main.c \
../MCAL/DIO/DIO.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
HAL/SSD/SSD.o \
main.o \
MCAL/DIO/DIO.o

OBJS_AS_ARGS +=  \
HAL/SSD/SSD.o \
main.o \
MCAL/DIO/DIO.o

C_DEPS +=  \
HAL/SSD/SSD.d \
main.d \
MCAL/DIO/DIO.d

C_DEPS_AS_ARGS +=  \
HAL/SSD/SSD.d \
main.d \
MCAL/DIO/DIO.d

OUTPUT_FILE_PATH +=SSD_Interface.elf

OUTPUT_FILE_PATH_AS_ARGS +=SSD_Interface.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
HAL/SSD/SSD.o: ../HAL/SSD/SSD.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../HAL/SSD" -I"../MCAL/DIO" -I"../Utilities"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../HAL/SSD" -I"../MCAL/DIO" -I"../Utilities"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

MCAL/DIO/DIO.o: ../MCAL/DIO/DIO.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../HAL/SSD" -I"../MCAL/DIO" -I"../Utilities"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SSD_Interface.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32a -B "D:\Microship Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "SSD_Interface.elf" "SSD_Interface.hex"
	"D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SSD_Interface.elf" "SSD_Interface.eep" || exit 0
	"D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SSD_Interface.elf" > "SSD_Interface.lss"
	"D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "SSD_Interface.elf" "SSD_Interface.srec"
	"D:\Microship Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "SSD_Interface.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SSD_Interface.elf" "SSD_Interface.a" "SSD_Interface.hex" "SSD_Interface.lss" "SSD_Interface.eep" "SSD_Interface.map" "SSD_Interface.srec" "SSD_Interface.usersignatures"
	