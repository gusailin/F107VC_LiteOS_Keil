################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Middlewares/LiteOS/arch/arm/arm-m/cortex-m3/gcc/los_dispatch_gcc.S 

OBJS += \
./Middlewares/LiteOS/arch/arm/arm-m/cortex-m3/gcc/los_dispatch_gcc.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LiteOS/arch/arm/arm-m/cortex-m3/gcc/%.o: ../Middlewares/LiteOS/arch/arm/arm-m/cortex-m3/gcc/%.S
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

