################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TADCasilla.cpp \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/entorno.cpp \
../src/main.cpp 

OBJS += \
./src/TADCasilla.o \
./src/TADJuego.o \
./src/TADTablero.o \
./src/entorno.o \
./src/main.o 

CPP_DEPS += \
./src/TADCasilla.d \
./src/TADJuego.d \
./src/TADTablero.d \
./src/entorno.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


