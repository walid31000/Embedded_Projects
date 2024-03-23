################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
seg_push_button.lss \

FLASH_IMAGE += \
seg_push_button.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: seg_push_button.elf secondary-outputs

# Tool invocations
seg_push_button.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,seg_push_button.map -mmcu=atmega32 -o "seg_push_button.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

seg_push_button.lss: seg_push_button.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S seg_push_button.elf  >"seg_push_button.lss"
	@echo 'Finished building: $@'
	@echo ' '

seg_push_button.hex: seg_push_button.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex seg_push_button.elf  "seg_push_button.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: seg_push_button.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 seg_push_button.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) seg_push_button.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
