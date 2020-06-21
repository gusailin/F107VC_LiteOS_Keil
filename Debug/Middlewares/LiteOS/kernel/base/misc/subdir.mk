################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LiteOS/kernel/base/misc/los_misc.c 

OBJS += \
./Middlewares/LiteOS/kernel/base/misc/los_misc.o 

C_DEPS += \
./Middlewares/LiteOS/kernel/base/misc/los_misc.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LiteOS/kernel/base/misc/los_misc.o: ../Middlewares/LiteOS/kernel/base/misc/los_misc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/misc/los_misc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

