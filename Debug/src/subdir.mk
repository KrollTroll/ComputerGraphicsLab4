################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gcontext.cpp \
../src/line.cpp \
../src/matrix.cpp \
../src/point.cpp \
../src/shape.cpp \
../src/test.cpp \
../src/triangle.cpp \
../src/x11context.cpp 

OBJS += \
./src/gcontext.o \
./src/line.o \
./src/matrix.o \
./src/point.o \
./src/shape.o \
./src/test.o \
./src/triangle.o \
./src/x11context.o 

CPP_DEPS += \
./src/gcontext.d \
./src/line.d \
./src/matrix.d \
./src/point.d \
./src/shape.d \
./src/test.d \
./src/triangle.d \
./src/x11context.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


