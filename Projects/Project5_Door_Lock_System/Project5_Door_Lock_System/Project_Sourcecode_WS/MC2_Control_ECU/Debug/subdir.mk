################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../Control_ECU_Application.c \
../DC_Motor.c \
../GPIO.c \
../HELP_Functions_Control.c \
../I2C.c \
../PWM.c \
../Timer1.c \
../UART.c \
../external_eeprom.c 

OBJS += \
./Buzzer.o \
./Control_ECU_Application.o \
./DC_Motor.o \
./GPIO.o \
./HELP_Functions_Control.o \
./I2C.o \
./PWM.o \
./Timer1.o \
./UART.o \
./external_eeprom.o 

C_DEPS += \
./Buzzer.d \
./Control_ECU_Application.d \
./DC_Motor.d \
./GPIO.d \
./HELP_Functions_Control.d \
./I2C.d \
./PWM.d \
./Timer1.d \
./UART.d \
./external_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


