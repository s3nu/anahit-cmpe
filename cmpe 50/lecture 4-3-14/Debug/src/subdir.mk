################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Polynomial-partial.cpp \
../src/lecture\ 4-3-14.cpp 

OBJS += \
./src/Polynomial-partial.o \
./src/lecture\ 4-3-14.o 

CPP_DEPS += \
./src/Polynomial-partial.d \
./src/lecture\ 4-3-14.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lecture\ 4-3-14.o: ../src/lecture\ 4-3-14.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/lecture 4-3-14.d" -MT"src/lecture\ 4-3-14.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


