################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/exam\ 4.cpp 

OBJS += \
./src/exam\ 4.o 

CPP_DEPS += \
./src/exam\ 4.d 


# Each subdirectory must supply rules for building sources it contributes
src/exam\ 4.o: ../src/exam\ 4.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/exam 4.d" -MT"src/exam\ 4.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


