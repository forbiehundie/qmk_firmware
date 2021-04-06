#pragma once

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Auto Shift */
#define AUTO_SHIFT_TIMEOUT 145
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_MODS

/* Tap-Hold Config */
#define TAPPING_TERM 170
#define TAPPING_FORCE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

/*Combos */
#ifdef COMBO_ENABLE
#    define COMBO_COUNT 9
#    define COMBO_TERM 200
#endif
