################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f401retx.s 

S_DEPS += \
./Core/Startup/startup_stm32f401retx.d 

OBJS += \
./Core/Startup/startup_stm32f401retx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32f401retx.o: ../Core/Startup/startup_stm32f401retx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32f401retx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

