################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/TI/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"F:/TI/mspm0-modules/Drivers/IMU660RB/Fusion" -I"F:/TI/mspm0-modules/Drivers/IMU660RB" -I"F:/TI/mspm0-modules/Drivers/LSM6DSV16X" -I"F:/TI/mspm0-modules/Drivers/VL53L0X" -I"F:/TI/mspm0-modules/Drivers/WIT" -I"F:/TI/mspm0-modules/Drivers/BNO08X_UART_RVC" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_GPIO" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_Capture" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_SPI" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_SPI" -I"F:/TI/mspm0-modules/Drivers/MPU6050" -I"F:/TI/mspm0-modules" -I"F:/TI/mspm0-modules/Debug" -I"C:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_05_01_00/source" -I"F:/TI/mspm0-modules/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1986194081: ../mspm0-modules.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"F:/TI/CCS/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "F:/TI/mspm0-modules/mspm0-modules.syscfg" -o "." -s "C:/TI/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1986194081 ../mspm0-modules.syscfg
device.opt: build-1986194081
device.cmd.genlibs: build-1986194081
ti_msp_dl_config.c: build-1986194081
ti_msp_dl_config.h: build-1986194081
Event.dot: build-1986194081

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/TI/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"F:/TI/mspm0-modules/Drivers/IMU660RB/Fusion" -I"F:/TI/mspm0-modules/Drivers/IMU660RB" -I"F:/TI/mspm0-modules/Drivers/LSM6DSV16X" -I"F:/TI/mspm0-modules/Drivers/VL53L0X" -I"F:/TI/mspm0-modules/Drivers/WIT" -I"F:/TI/mspm0-modules/Drivers/BNO08X_UART_RVC" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_GPIO" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_Capture" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_SPI" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_SPI" -I"F:/TI/mspm0-modules/Drivers/MPU6050" -I"F:/TI/mspm0-modules" -I"F:/TI/mspm0-modules/Debug" -I"C:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_05_01_00/source" -I"F:/TI/mspm0-modules/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/TI/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/TI/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"F:/TI/mspm0-modules/Drivers/IMU660RB/Fusion" -I"F:/TI/mspm0-modules/Drivers/IMU660RB" -I"F:/TI/mspm0-modules/Drivers/LSM6DSV16X" -I"F:/TI/mspm0-modules/Drivers/VL53L0X" -I"F:/TI/mspm0-modules/Drivers/WIT" -I"F:/TI/mspm0-modules/Drivers/BNO08X_UART_RVC" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_GPIO" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_Capture" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_SPI" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_SPI" -I"F:/TI/mspm0-modules/Drivers/MPU6050" -I"F:/TI/mspm0-modules" -I"F:/TI/mspm0-modules/Debug" -I"C:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_05_01_00/source" -I"F:/TI/mspm0-modules/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


