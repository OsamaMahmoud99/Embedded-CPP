#Author: Ahmed Ashraf
#Purpose: This makefile is used for avr development purposes
#Version: v1.2
#Date: 16-4-2022

##################################### Development parameters ######################################

#CPP include directory
CPP_INC_DIR := -I../LIB
CPP_INC_DIR += -I../MCAL/MDIO
CPP_INC_DIR += -I../MCAL/MPWM
CPP_INC_DIR += -I../MCAL/MUART
CPP_INC_DIR += -I../HAL/HBUZZER
CPP_INC_DIR += -I../HAL/HLED
CPP_INC_DIR += -I../HAL/HMOTOR
CPP_INC_DIR += -I../HAL/HBLTH
CPP_INC_DIR += -I../SERVICE
CPP_INC_DIR += -I../APP/Bluetooth_RC_Car


#CPP source files
CPP_SRC_FILES := ../main.cpp
CPP_SRC_FILES += ../APP/Bluetooth_RC_Car/Bluetooth_RC_Car_program.cpp
CPP_SRC_FILES += ../SERVICE/STTS_program.cpp
CPP_SRC_FILES += ../HAL/HBUZZER/HBUZZER_program.cpp
CPP_SRC_FILES += ../HAL/HBUZZER/HBUZZER_cfg.cpp
CPP_SRC_FILES += ../HAL/HLED/HLED_program.cpp
CPP_SRC_FILES += ../HAL/HLED/HLED_cfg.cpp
CPP_SRC_FILES += ../HAL/HMOTOR/HMOTOR_program.cpp
CPP_SRC_FILES += ../HAL/HMOTOR/HMOTOR_cfg.cpp
CPP_SRC_FILES += ../HAL/HBLTH/HBLTH_program.cpp
CPP_SRC_FILES += ../HAL/HBLTH/HBLTH_cfg.cpp
CPP_SRC_FILES += ../MCAL/MDIO/MDIO_program.cpp
CPP_SRC_FILES += ../MCAL/MPWM/MPWM_program.cpp
CPP_SRC_FILES += ../MCAL/MUART/MUART_program.cpp




#CPP object files
CPP_OBJ_FILES := main.o
CPP_OBJ_FILES += Bluetooth_RC_Car_program.o
CPP_OBJ_FILES += STTS_program.o
CPP_OBJ_FILES += HBUZZER_program.o
CPP_OBJ_FILES += HBUZZER_cfg.o
CPP_OBJ_FILES += HLED_program.o
CPP_OBJ_FILES += HLED_cfg.o
CPP_OBJ_FILES += HMOTOR_program.o
CPP_OBJ_FILES += HMOTOR_cfg.o
CPP_OBJ_FILES += HBLTH_program.o
CPP_OBJ_FILES += HBLTH_cfg.o
CPP_OBJ_FILES += MDIO_program.o
CPP_OBJ_FILES += MPWM_program.o
CPP_OBJ_FILES += MUART_program.o



#ELF file name
ELF_FILE := main.elf

#HEX file name
HEX_FILE := main.hex

#MAP file name
MAP_FILE := main.map

#Defining the CPU parameters
F_CPU := 4000000UL
MCU := atmega8

#Defining compiler parameters
COMPILER := avr-g++
COMPILER_OPTIONS := -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(CPP_INC_DIR)

############################################## Rules ##############################################

#Building binaries command - DEP[clean, elf file]
all: clean main.hex

#Generating the elf file
main.elf:
	@echo "Building target..."
	@echo "Invoking AVR Compiler..."
	@$(COMPILER) $(COMPILER_OPTIONS) -c $(CPP_SRC_FILES)
	@echo "Invoking AVR Linker..."
	@$(COMPILER) -Wl,-Map,$(MAP_FILE) -mmcu=$(MCU) -o $(ELF_FILE) $(CPP_OBJ_FILES)
	@echo "ELF file generated"

main.hex: main.elf
	@echo "Creating flash image..."
	@avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex $(ELF_FILE) $(HEX_FILE)
	@echo "Flash image generated"
	@echo "Printing program size"
	@avr-size --format=avr --mcu=atmega8 $(ELF_FILE)
	@echo "Build finished"

#Binaries cleaning rule - No DEP
clean:
	@rm -rf *.o *.hex *.elf *.map