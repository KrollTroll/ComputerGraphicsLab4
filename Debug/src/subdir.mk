################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gcontext.cpp \
../src/matrix.cpp \
../src/point.cpp \
../src/shape.cpp 

OBJS += \
./src/gcontext.o \
./src/matrix.o \
./src/point.o \
./src/shape.o 

CPP_DEPS += \
./src/gcontext.d \
./src/matrix.d \
./src/point.d \
./src/shape.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


