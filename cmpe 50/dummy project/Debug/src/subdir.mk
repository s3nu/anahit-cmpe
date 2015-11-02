################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dummy\ project.cpp 

OBJS += \
./src/dummy\ project.o 

CPP_DEPS += \
./src/dummy\ project.d 


# Each subdirectory must supply rules for building sources it contributes
src/dummy\ project.o: ../src/dummy\ project.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/dummy project.d" -MT"src/dummy\ project.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


