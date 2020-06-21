################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/LiteOS/kernel/extended/tickless/subdir.mk
-include Middlewares/LiteOS/kernel/base/om/subdir.mk
-include Middlewares/LiteOS/kernel/base/misc/subdir.mk
-include Middlewares/LiteOS/kernel/base/mem/common/subdir.mk
-include Middlewares/LiteOS/kernel/base/mem/bestfit_little/subdir.mk
-include Middlewares/LiteOS/kernel/base/ipc/subdir.mk
-include Middlewares/LiteOS/kernel/base/core/subdir.mk
-include Middlewares/LiteOS/kernel/subdir.mk
-include Middlewares/LiteOS/arch/arm/common/unwind/subdir.mk
-include Middlewares/LiteOS/arch/arm/arm-m/src/subdir.mk
-include Middlewares/LiteOS/arch/arm/arm-m/cortex-m3/gcc/subdir.mk
-include Hardware/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Components/net/lwip/lwip_port/OS/subdir.mk
-include Components/net/lwip/lwip-2.1.2/src/netif/subdir.mk
-include Components/net/lwip/lwip-2.1.2/src/core/ipv6/subdir.mk
-include Components/net/lwip/lwip-2.1.2/src/core/ipv4/subdir.mk
-include Components/net/lwip/lwip-2.1.2/src/core/subdir.mk
-include Components/net/lwip/lwip-2.1.2/src/api/subdir.mk
-include Components/net/at_frame/subdir.mk
-include Components/log/subdir.mk
-include Components/lib/libc/subdir.mk
-include Components/lib/cJSON/subdir.mk
-include Components/fs/vfs/subdir.mk
-include Components/fs/kifs/subdir.mk
-include Components/fs/devfs/subdir.mk
-include Components/connectivity/mqtt/MQTTPacket/src/subdir.mk
-include Components/connectivity/mqtt/MQTTClient-C/src/liteOS/subdir.mk
-include Components/connectivity/mqtt/MQTTClient-C/src/subdir.mk
-include App/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F107VC_LiteOS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F107VC_LiteOS.list \

OBJCOPY_BIN += \
F107VC_LiteOS.bin \


# All Target
all: F107VC_LiteOS.elf secondary-outputs

# Tool invocations
F107VC_LiteOS.elf: $(OBJS) $(USER_OBJS) G:\STM32CubeIDE\F107VC_LiteOS\STM32F107VCTX_FLASH.ld
	arm-none-eabi-gcc -o "F107VC_LiteOS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"G:\STM32CubeIDE\F107VC_LiteOS\STM32F107VCTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F107VC_LiteOS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F107VC_LiteOS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F107VC_LiteOS.list"
	@echo 'Finished building: $@'
	@echo ' '

F107VC_LiteOS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "F107VC_LiteOS.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
