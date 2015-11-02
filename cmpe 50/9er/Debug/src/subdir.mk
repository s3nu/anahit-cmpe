################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/9er.cpp \
../src/admin.cpp \
../src/employee.cpp \
../src/salariedemployee.cpp 

OBJS += \
./src/9er.o \
./src/admin.o \
./src/employee.o \
./src/salariedemployee.o 

CPP_DEPS += \
./src/9er.d \
./src/admin.d \
./src/employee.d \
./src/salariedemployee.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


