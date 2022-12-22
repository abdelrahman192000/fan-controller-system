################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../dc_motor.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../motor_controll.c \
../timer_pwm.c 

OBJS += \
./adc.o \
./dc_motor.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./motor_controll.o \
./timer_pwm.o 

C_DEPS += \
./adc.d \
./dc_motor.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./motor_controll.d \
./timer_pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


