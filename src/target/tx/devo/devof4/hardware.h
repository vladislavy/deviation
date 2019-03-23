#ifndef _DEVOF7_HARDWARE_H_
#define _DEVOF7_HARDWARE_H_

#define BUTTON_MATRIX { \
/*         C.6              C.7              C.8              C.9         */   \
/*B.5*/    BUT_LEFT,        BUT_RIGHT,       BUT_ENTER,       BUT_LAST,        \
/*B.6*/    BUT_DOWN,        BUT_UP,          BUT_EXIT,        BUT_LAST+1,      \
/*B.7*/    BUT_TRIM_RH_NEG, BUT_TRIM_RH_POS, BUT_TRIM_LH_NEG, BUT_TRIM_LH_POS, \
/*B.8*/    BUT_TRIM_LV_NEG, BUT_TRIM_RV_NEG, BUT_TRIM_LV_POS, BUT_TRIM_RV_POS, \
    }

#define BUTTON_MATRIX_ROW_OD ((struct mcu_pin){GPIOB, GPIO5 | GPIO6 | GPIO7 | GPIO8})
#define BUTTON_MATRIX_COL_PU ((struct mcu_pin){GPIOC, GPIO6 | GPIO7 | GPIO8 | GPIO9})
#define EXTRA_SWITCH_COL_OD ((struct mcu_pin){GPIOC, GPIO6})

// Analog inputs
#define ADC_CHANNELS { \
    ADC_CHAN(GPIOC, GPIO2, CHAN_NONINV),  /* ADC123_12 - INP_AIL */ \
    ADC_CHAN(GPIOC, GPIO1, CHAN_NONINV),  /* ADC123_11 - INP_ELE */ \
    ADC_CHAN(GPIOC, GPIO0, CHAN_INVERT),  /* ADC123_10 - INP_THR */ \
    ADC_CHAN(GPIOC, GPIO3, CHAN_INVERT),  /* ADC123_13 - INP_RUD */ \
    ADC_CHAN(0, 16, CHAN_NONINV),         /* TEMPERATURE */ \
    ADC_CHAN(GPIOC, GPIO4, CHAN_NONINV),  /* ADC12_14  */ \
    }

#define SWITCHES \
    TWO_WAY(INP_AIL_DR, (GPIOC, GPIO13), CHAN_INVERT) \
    TWO_WAY(INP_GEAR, (GPIOC, GPIO14), CHAN_INVERT) \
    THREE_WAY(INP_MIX, (GPIOB, GPIO4), (GPIOB, GPIO3), CHAN_INVERT) \
    THREE_WAY(INP_FMOD, (GPIOC, GPIO11), (GPIOC, GPIO10), CHAN_INVERT)

#define ADDON_SWITCH_CFG \
    ADDON_SWITCH("2x2", SWITCH_2x2, 0) \
    ADDON_SWITCH("3x1", SWITCH_3x1, 0) \
    ADDON_SWITCH("3x2", SWITCH_3x2, 0)

#define EXTRA_SWITCHES \
    EXTRA_3WAY(INP_SWA, 0x04, 0x08, CHAN_NONINV, SWITCH_3x2) \
    EXTRA_3WAY(INP_SWB, 0x01, 0x02, CHAN_NONINV, SWITCH_3x2) \
    EXTRA_2WAY(INP_SWA, 0x04, 0x08, CHAN_INVERT, SWITCH_2x2) \
    EXTRA_2WAY(INP_SWB, 0x01, 0x02, CHAN_INVERT, SWITCH_2x2)

#define SWITCH_2x2  ((1 << INP_SWA0) | (1 << INP_SWA1) | (1 << INP_SWB0) | (1 << INP_SWB1))
#define SWITCH_3x1  ((1 << INP_SWB0) | (1 << INP_SWB1) | (1 << INP_SWB2))
#define SWITCH_3x2  ((1 << INP_SWA0) | (1 << INP_SWA1) | (1 << INP_SWA2) | SWITCH_3x1)
#define SWITCH_STOCK (~(SWITCH_2x2 | SWITCH_3x2))

#define LCD_VIDEO_CS0 ((struct mcu_pin){GPIOA, GPIO0})
#define LCD_VIDEO_CS1 ((struct mcu_pin){GPIOA, GPIO8})
#define LCD_VIDEO_CS2 ((struct mcu_pin){GPIOA, GPIO15})
#define LCD_VIDEO_PWR ((struct mcu_pin){GPIOB, GPIO9})

#endif  // _DEVOF7_HARDWARE_H_
