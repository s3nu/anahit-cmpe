################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Polynomial.cpp \
../src/lap\ 8.cpp 

OBJS += \
./src/Polynomial.o \
./src/lap\ 8.o 

CPP_DEPS += \
./src/Polynomial.d \
./src/lap\ 8.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lap\ 8.o: ../src/lap\ 8.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lap 8.d" -MT"src/lap\ 8.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


