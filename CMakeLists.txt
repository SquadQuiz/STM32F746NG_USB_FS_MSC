cmake_minimum_required(VERSION 3.22)

include("cmake/gcc-arm-none-eabi.cmake")

# Core project settings
project(STM32F746NG_USB_FS_MSC)
enable_language(C CXX ASM)
message("Build type: " ${CMAKE_BUILD_TYPE})

# Setup compiler settings
set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
set(PROJ_PATH                       ${CMAKE_CURRENT_SOURCE_DIR})


# Core MCU flags, CPU type, instruction set and FPU setup
set(cpu_PARAMS 

)

# Sources
set(sources_SRCS
	# Put here your source files, one in each line, relative to CMakeLists.txt file location
    # Core Source files
    ${PROJ_PATH}/Core/Src/main.c
    ${PROJ_PATH}/Core/Src/stm32f7xx_it.c
    ${PROJ_PATH}/Core/Src/syscall.c
    ${PROJ_PATH}/Core/Src/sysmem.c
    ${PROJ_PATH}/Core/Src/system_stm32f7xx.c
    
    # HAL Driver
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c

    ## LL Drivers
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c
    
    # BSP Drivers
    ${PROJ_PATH}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c
    ${PROJ_PATH}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c
    
    # Middlewares
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_bot.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_data.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_scsi.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
  
    # Application
    ${PROJ_PATH}/Application/USBMSC/Src/usbd_conf.c
    ${PROJ_PATH}/Application/USBMSC/Src/usbd_desc.c
    ${PROJ_PATH}/Application/USBMSC/Src/usbd_msc_storage.c

    # Startup
    ${PROJ_PATH}/Core/Startup/startup_stm32f746nghx.s
)

# Include directories for all compilers
set(include_DIRS
    # Put here your include dirs, one in each line, relative to CMakeLists.txt file location
    ${PROJ_PATH}/Core/Inc
    # Drivers
    ${PROJ_PATH}/Drivers/CMSIS/Include
    ${PROJ_PATH}/Drivers/CMSIS/Device/ST/STM32F7xx/Include
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Inc
    ${PROJ_PATH}/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy
    # BSP
    ${PROJ_PATH}/Drivers/BSP/STM32746G-Discovery/
    # Middlewares
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc
    ${PROJ_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    # Application
    ${PROJ_PATH}/Application/USBMSC/Inc

)

# Include directories for each compiler
set(include_c_DIRS)
set(include_cxx_DIRS)
set(include_asm_DIRS)

# Symbols definition for all compilers
set(symbols_SYMB
    # Put here your symbols (preprocessor defines), one in each line
    # Encapsulate them with double quotes for safety purpose
)

# Symbols definition for each compiler
set(symbols_c_SYMB)
set(symbols_cxx_SYMB)
set(symbols_asm_SYMB)

# Link directories and names of libraries
set(link_DIRS)
set(link_LIBS)

# Linker script
set(linker_script_SRC)

# Compiler options
set(compiler_OPTS)

# Linker options
set(linker_OPTS)

# information to the project
include("cmake/toolchain-setting.cmake")

# Link directories setup
# Must be before executable is added
link_directories(${CMAKE_PROJECT_NAME} ${link_DIRS})

# Executable files
add_executable(${CMAKE_PROJECT_NAME} 
	${sources_SRCS}
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PUBLIC 
	${sources_SRCS}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${include_DIRS}
    $<$<COMPILE_LANGUAGE:C>: ${include_c_DIRS}>
    $<$<COMPILE_LANGUAGE:CXX>: ${include_cxx_DIRS}>
    $<$<COMPILE_LANGUAGE:ASM>: ${include_asm_DIRS}>
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
	${symbols_SYMB}
  
  # Preprocessor
	USE_HAL_DRIVER
	STM32F746xx
	USE_STM32746G_DISCO

	$<$<CONFIG:Debug>:DEBUG>
	$<$<COMPILE_LANGUAGE:C>: ${symbols_c_SYMB}>
	$<$<COMPILE_LANGUAGE:CXX>: ${symbols_cxx_SYMB}>
	$<$<COMPILE_LANGUAGE:ASM>: ${symbols_asm_SYMB}>

	# Configuration specific
	$<$<CONFIG:Debug>:DEBUG>
	$<$<CONFIG:Release>: >
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME} 
	${link_LIBS}
)

# Compiler options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    ${cpu_PARAMS}
    ${compiler_OPTS}
)

# Linker options
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    -T${linker_script_SRC}
    ${cpu_PARAMS}
    ${linker_OPTS}
)

set(EXECUTABLE_NAME
	${CMAKE_PROJECT_NAME}
)

# Execute post-build to print size, generate hex and bin
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE_NAME}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE_NAME}> ${EXECUTABLE_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE_NAME}> ${EXECUTABLE_NAME}.bin
)