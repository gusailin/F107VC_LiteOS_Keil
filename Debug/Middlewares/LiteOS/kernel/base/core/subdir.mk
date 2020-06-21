################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/LiteOS/kernel/base/core/los_priqueue.c \
../Middlewares/LiteOS/kernel/base/core/los_swtmr.c \
../Middlewares/LiteOS/kernel/base/core/los_sys.c \
../Middlewares/LiteOS/kernel/base/core/los_task.c \
../Middlewares/LiteOS/kernel/base/core/los_tick.c \
../Middlewares/LiteOS/kernel/base/core/los_timeslice.c 

OBJS += \
./Middlewares/LiteOS/kernel/base/core/los_priqueue.o \
./Middlewares/LiteOS/kernel/base/core/los_swtmr.o \
./Middlewares/LiteOS/kernel/base/core/los_sys.o \
./Middlewares/LiteOS/kernel/base/core/los_task.o \
./Middlewares/LiteOS/kernel/base/core/los_tick.o \
./Middlewares/LiteOS/kernel/base/core/los_timeslice.o 

C_DEPS += \
./Middlewares/LiteOS/kernel/base/core/los_priqueue.d \
./Middlewares/LiteOS/kernel/base/core/los_swtmr.d \
./Middlewares/LiteOS/kernel/base/core/los_sys.d \
./Middlewares/LiteOS/kernel/base/core/los_task.d \
./Middlewares/LiteOS/kernel/base/core/los_tick.d \
./Middlewares/LiteOS/kernel/base/core/los_timeslice.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LiteOS/kernel/base/core/los_priqueue.o: ../Middlewares/LiteOS/kernel/base/core/los_priqueue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_priqueue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/kernel/base/core/los_swtmr.o: ../Middlewares/LiteOS/kernel/base/core/los_swtmr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_swtmr.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/kernel/base/core/los_sys.o: ../Middlewares/LiteOS/kernel/base/core/los_sys.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_sys.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/kernel/base/core/los_task.o: ../Middlewares/LiteOS/kernel/base/core/los_task.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_task.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/kernel/base/core/los_tick.o: ../Middlewares/LiteOS/kernel/base/core/los_tick.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_tick.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LiteOS/kernel/base/core/los_timeslice.o: ../Middlewares/LiteOS/kernel/base/core/los_timeslice.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F107xC -DDEBUG -c -I../Middlewares/LiteOS/kernel/extended/include -I../Middlewares/LiteOS/arch/arm/arm-m/include -I../Components/connectivity/mqtt/MQTTClient-C/src -I../Components/Inc/fs -I../Components/connectivity/mqtt/MQTTClient-C/src/liteOS -I../Components/Inc -I../Middlewares/LiteOS/arch/arm/include -I../Middlewares/LiteOS/kernel/base/include -I../App/Inc -I../Components/net/lwip/lwip_port -I../Components/net/lwip/lwip_port/OS -I../Components/net/lwip/lwip-2.1.2/src/include -I../OS_CONFIG -I../Middlewares/LiteOS/kernel/include -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Hardware/Inc -I../Components/lib/cJSON -I../Components/connectivity/mqtt/MQTTPacket/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Components/net/lwip/lwip_port/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LiteOS/kernel/base/core/los_timeslice.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

