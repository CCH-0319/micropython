/*
 * This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (C) 2013-2025 OpenMV, LLC.
 */

#define MICROPY_HW_BOARD_NAME       "CCH-VGT6"
#define MICROPY_HW_MCU_NAME         "STM32H743"
#define MICROPY_PY_SYS_PLATFORM     "OpenMV4-H7"
#define MICROPY_HW_FLASH_FS_LABEL   "CCH USB"

// Network config
#define MICROPY_PY_NETWORK_HOSTNAME_DEFAULT "mpy-openmv-4"

#define MICROPY_OBJ_REPR            (MICROPY_OBJ_REPR_C)
#define UINT_FMT                    "%u"
#define INT_FMT                     "%d"
typedef int mp_int_t;               // must be pointer size
typedef unsigned int mp_uint_t;     // must be pointer size

#define MICROPY_FATFS_EXFAT         (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_SPI2      (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_ENTER_BOOTLOADER_VIA_RESET   (0)
#define MICROPY_HW_TIM_IS_RESERVED(id) (id == 1 || id == 6)

// ROMFS config
#define MICROPY_HW_ROMFS_ENABLE_INTERNAL_FLASH  (1)
#define MICROPY_HW_ROMFS_ENABLE_PART0           (1)

#define MICROPY_BOARD_ENTER_STANDBY

extern void board_enter_bootloader(void);
#define MICROPY_BOARD_ENTER_BOOTLOADER(nargs, args) board_enter_bootloader()

// Note these are not used in top system.c.
#define MICROPY_HW_CLK_PLLM         (5)     // 25/5=5 MHz
#define MICROPY_HW_CLK_PLLN         (192)   // 5*192=960 MHz (VCO)
#define MICROPY_HW_CLK_PLLP         (2)     // 960/2=480 MHz SYSCLK
#define MICROPY_HW_CLK_PLLQ         (20)    // 960/20=48 MHz (USB)
#define MICROPY_HW_CLK_PLLR         (2)     // 960/2=480 MHz
#define MICROPY_HW_CLK_PLLVCI       (RCC_PLL1VCIRANGE_2)
#define MICROPY_HW_CLK_PLLVCO       (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC      (0)

// I2C buses
#define MICROPY_HW_I2C1_SCL (pin_B8)
#define MICROPY_HW_I2C1_SDA (pin_B9)

#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

// SPI buses
#define MICROPY_HW_SPI3_SCK  (pin_B3)
#define MICROPY_HW_SPI3_MISO (pin_B4)
#define MICROPY_HW_SPI3_MOSI (pin_B5)
#define MICROPY_HW_SPI3_NSS  (pin_A15)

#define MICROPY_HW_SPI4_SCK  (pin_E12)
#define MICROPY_HW_SPI4_MISO (pin_E13)
#define MICROPY_HW_SPI4_MOSI (pin_E14)
#define MICROPY_HW_SPI4_NSS  (pin_E11)

// UART config
#define MICROPY_HW_UART1_TX  (pin_A9)
#define MICROPY_HW_UART1_RX  (pin_A10)

#define MICROPY_HW_UART2_TX  (pin_A2)
#define MICROPY_HW_UART2_RX  (pin_A3)

#define MICROPY_HW_UART3_TX  (pin_D8)
#define MICROPY_HW_UART3_RX  (pin_D9)

// FDCAN bus
#define MICROPY_HW_CAN2_NAME "FDCAN2"
#define MICROPY_HW_CAN2_RX   (pin_B12)
#define MICROPY_HW_CAN2_TX   (pin_B13)
#define MICROPY_HW_CAN_IS_RESERVED(id) (id != PYB_CAN_2)

// SD card detect switch
#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_C0)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)

// USB config
#define MICROPY_HW_USB_FS                   (1)
#define MICROPY_HW_USB_CDC_RX_DATA_SIZE     (512)
#define MICROPY_HW_USB_CDC_TX_DATA_SIZE     (512)
//#define MICROPY_HW_USB_VBUS_DETECT_PIN      (pin_A9)

// LEDs
#define MICROPY_HW_LED1             (pin_E7) // red
#define MICROPY_HW_LED2             (pin_E8) // green
#define MICROPY_HW_LED3             (pin_C13) // blue
#define MICROPY_HW_LED4             (pin_E9) // IR
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
// NOTE: LEDs are active low.
#define MICROPY_HW_LED_ON(pin)      (pin->gpio->BSRR = (pin->pin_mask << 16))
#define MICROPY_HW_LED_OFF(pin)     (pin->gpio->BSRR = pin->pin_mask)

// Servos
#define PYB_SERVO_NUM (4)

// Board network interfaces config.
#if MICROPY_PY_WINC1500
extern const struct _mp_obj_type_t mod_network_nic_type_winc;
#define MICROPY_PY_USOCKET_EXTENDED_STATE   (1)
#define MICROPY_BOARD_NETWORK_INTERFACES \
    { MP_ROM_QSTR(MP_QSTR_WINC), MP_ROM_PTR(&mod_network_nic_type_winc) },\
    { MP_ROM_QSTR(MP_QSTR_WLAN), MP_ROM_PTR(&mod_network_nic_type_winc) },
#else
#define MICROPY_BOARD_NETWORK_INTERFACES
#endif

#define MICROPY_HW_USB_VID                      0x37C5
#define MICROPY_HW_USB_PID                      0x1204
#define MICROPY_HW_USB_PID_CDC_MSC              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_HID              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_MSC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_MSC_HID          (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_LANGID_STRING            0x409
#define MICROPY_HW_USB_MANUFACTURER_STRING      "CC"  //"OpenMV"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "CCH Virtual Comm Port in FS Mode"  //"OpenMV Virtual Comm Port in FS Mode"
#define MICROPY_HW_USB_PRODUCT_HS_STRING        "CCH Virtual Comm Port in HS Mode"  //"OpenMV Virtual Comm Port in HS Mode"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "VCP Interface"
#define MICROPY_HW_USB_INTERFACE_HS_STRING      "VCP Interface"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "VCP Config"
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  "VCP Config"
