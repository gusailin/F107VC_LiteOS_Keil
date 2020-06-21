################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.c \
../Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.c \
../Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.c 

OBJS += \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.o \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.o \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.o 

C_DEPS += \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.d \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.d \
./Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.o: ../Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/arch/arm/arm-m/src/los_hw.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.o: ../Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/arch/arm/arm-m/src/los_hw_tick.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.o: ../Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/arch/arm/arm-m/src/los_hwi.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

