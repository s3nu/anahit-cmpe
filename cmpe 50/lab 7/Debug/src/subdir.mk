################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lab\ 7.cpp 

OBJS += \
./src/lab\ 7.o 

CPP_DEPS += \
./src/lab\ 7.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab\ 7.o: ../src/lab\ 7.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lab 7.d" -MT"src/lab\ 7.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


