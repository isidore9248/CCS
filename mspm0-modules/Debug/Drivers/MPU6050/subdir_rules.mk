################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/MPU6050/%.o: ../Drivers/MPU6050/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"F:/TI/CCS/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"F:/TI/mspm0-modules/Drivers/IMU660RB/Fusion" -I"F:/TI/mspm0-modules/Drivers/IMU660RB" -I"F:/TI/mspm0-modules/Drivers/LSM6DSV16X" -I"F:/TI/mspm0-modules/Drivers/VL53L0X" -I"F:/TI/mspm0-modules/Drivers/WIT" -I"F:/TI/mspm0-modules/Drivers/BNO08X_UART_RVC" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_GPIO" -I"F:/TI/mspm0-modules/Drivers/Ultrasonic_Capture" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Hardware_SPI" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_I2C" -I"F:/TI/mspm0-modules/Drivers/OLED_Software_SPI" -I"F:/TI/mspm0-modules/Drivers/MPU6050" -I"F:/TI/mspm0-modules" -I"F:/TI/mspm0-modules/Debug" -I"C:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_05_01_00/source" -I"F:/TI/mspm0-modules/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/MPU6050/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


