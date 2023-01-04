################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../HELP_Functions_HMI.c \
../HMI_Application.c \
../KEYPAD.c \
../LCD.c \
../Timer1.c \
../UART.c 

OBJS += \
./GPIO.o \
./HELP_Functions_HMI.o \
./HMI_Application.o \
./KEYPAD.o \
./LCD.o \
./Timer1.o \
./UART.o 

C_DEPS += \
./GPIO.d \
./HELP_Functions_HMI.d \
./HMI_Application.d \
./KEYPAD.d \
./LCD.d \
./Timer1.d \
./UART.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


