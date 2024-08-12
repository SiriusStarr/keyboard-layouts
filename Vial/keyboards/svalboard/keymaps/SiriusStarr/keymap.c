#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "layout.h"
#include "keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = LAYOUT(
            /* Center      North       East         South          West         Double-south */
        /*R1*/ R_1_H_BASE, R_1_T_BASE, XXXXXXX,     R_1_B_BASE,    R_I_H_BASE,  XXXXXXX,
        /*R2*/ R_2_H_BASE, R_2_T_BASE, XXXXXXX,     R_2_B_BASE,    R_I_T_BASE,  XXXXXXX,
        /*R3*/ R_3_H_BASE, R_3_T_BASE, XXXXXXX,     R_3_B_BASE,    R_I_B_BASE,  XXXXXXX,
        /*R4*/ R_4_H_BASE, R_4_T_BASE, XXXXXXX,     R_4_B_BASE,    COMBO_QU,    XXXXXXX,

        /*L1*/ L_1_H_BASE, L_1_T_BASE, L_I_H_BASE,  L_1_B_BASE,    XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_BASE, L_2_T_BASE, L_I_T_BASE,  L_2_B_BASE,    XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_BASE, L_3_T_BASE, L_I_B_BASE,  L_3_B_BASE,    XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_BASE, L_4_T_BASE, KC_Z,        L_4_B_BASE,    XXXXXXX,     XXXXXXX,

            /* Down        Inner (pad) Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_BASE, R_T_1_BASE, KC_F24,      R_T_3_BASE,    XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_BASE, L_T_1_BASE, KC_F24,      L_T_3_BASE,    XXXXXXX,     XXXXXXX
    ),

    [NUMBER_AND_SYMBOL] = LAYOUT(
            /* Center      North       East         South          West         Double-south */
        /*R1*/ R_1_H_NAS,  R_1_T_NAS,  XXXXXXX,     R_1_B_NAS,     R_I_H_NAS,   XXXXXXX,
        /*R2*/ R_2_H_NAS,  R_2_T_NAS,  XXXXXXX,     R_2_B_NAS,     R_I_T_NAS,   XXXXXXX,
        /*R3*/ R_3_H_NAS,  R_3_T_NAS,  XXXXXXX,     R_3_B_NAS,     R_I_B_NAS,   XXXXXXX,
        /*R4*/ R_4_H_NAS,  R_4_T_NAS,  XXXXXXX,     R_4_B_NAS,     XXXXXXX,     XXXXXXX,

        /*L1*/ L_1_H_NAS,  L_1_T_NAS,  L_I_H_NAS,   L_1_B_NAS,     XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_NAS,  L_2_T_NAS,  L_I_T_NAS,   L_2_B_NAS,     XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_NAS,  L_3_T_NAS,  L_I_B_NAS,   L_3_B_NAS,     XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_NAS,  L_4_T_NAS,  XXXXXXX,     L_4_B_NAS,     XXXXXXX,     XXXXXXX,

            /* Down        Inner (pad) Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_NAS,  R_T_1_NAS,  XXXXXXX,     R_T_3_NAS,     XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_NAS,  L_T_1_NAS,  XXXXXXX,     L_T_3_NAS,     XXXXXXX,     XXXXXXX
    ),

    [NAVIGATION] = LAYOUT(
            /* Center      North       East         South          West         Double-south */
        /*R1*/ R_1_H_NAV,  R_1_T_NAV,  XXXXXXX,     R_1_B_NAV,     R_I_H_NAV,   XXXXXXX,
        /*R2*/ R_2_H_NAV,  R_2_T_NAV,  XXXXXXX,     R_2_B_NAV,     R_I_T_NAV,   XXXXXXX,
        /*R3*/ R_3_H_NAV,  R_3_T_NAV,  XXXXXXX,     R_3_B_NAV,     R_I_B_NAV,   XXXXXXX,
        /*R4*/ R_4_H_NAV,  R_4_T_NAV,  XXXXXXX,     R_4_B_NAV,     XXXXXXX,     XXXXXXX,

        /*L1*/ L_1_H_NAV,  L_1_T_NAV,  L_I_H_NAV,   L_1_B_NAV,     XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_NAV,  L_2_T_NAV,  L_I_T_NAV,   L_2_B_NAV,     XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_NAV,  L_3_T_NAV,  L_I_B_NAV,   L_3_B_NAV,     XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_NAV,  L_4_T_NAV,  XXXXXXX,     L_4_B_NAV,     XXXXXXX,     XXXXXXX,

            /* Down        Inner (pad) Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_NAV,  R_T_1_NAV,  XXXXXXX,     R_T_3_NAV,     XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_NAV,  L_T_1_NAV,  XXXXXXX,     L_T_3_NAV,     XXXXXXX,     XXXXXXX
    ),

    [FUNCTION_AND_MEDIA] = LAYOUT(
            /* Center      North       East         South          West         Double-south */
        /*R1*/ R_1_H_FAM,  R_1_T_FAM,  XXXXXXX,     R_1_B_FAM,     R_I_H_FAM,   XXXXXXX,
        /*R2*/ R_2_H_FAM,  R_2_T_FAM,  XXXXXXX,     R_2_B_FAM,     R_I_T_FAM,   XXXXXXX,
        /*R3*/ R_3_H_FAM,  R_3_T_FAM,  XXXXXXX,     R_3_B_FAM,     R_I_B_FAM,   XXXXXXX,
        /*R4*/ R_4_H_FAM,  R_4_T_FAM,  XXXXXXX,     R_4_B_FAM,     XXXXXXX,     XXXXXXX,

        /*L1*/ L_1_H_FAM,  L_1_T_FAM,  L_I_H_FAM,   L_1_B_FAM,     XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_FAM,  L_2_T_FAM,  L_I_T_FAM,   L_2_B_FAM,     XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_FAM,  L_3_T_FAM,  L_I_B_FAM,   L_3_B_FAM,     XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_FAM,  L_4_T_FAM,  XXXXXXX,     L_4_B_FAM,     XXXXXXX,     XXXXXXX,

            /* Down        Inner (pad) Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_FAM,  R_T_1_FAM,  XXXXXXX,     R_T_3_FAM,     XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_FAM,  L_T_1_FAM,  XXXXXXX,     L_T_3_FAM,     XXXXXXX,     XXXXXXX
    ),

    [MOUSE] = LAYOUT(
            /* Center       North        East         South          West         Double-south */
        /*R1*/ R_1_H_MOUSE, R_1_T_MOUSE, XXXXXXX,     R_1_B_MOUSE,   R_I_H_MOUSE, XXXXXXX,
        /*R2*/ R_2_H_MOUSE, R_2_T_MOUSE, XXXXXXX,     R_2_B_MOUSE,   R_I_T_MOUSE, XXXXXXX,
        /*R3*/ R_3_H_MOUSE, R_3_T_MOUSE, XXXXXXX,     R_3_B_MOUSE,   R_I_B_MOUSE, XXXXXXX,
        /*R4*/ R_4_H_MOUSE, R_4_T_MOUSE, XXXXXXX,     R_4_B_MOUSE,   XXXXXXX,     XXXXXXX,

        /*L1*/ L_1_H_MOUSE, L_1_T_MOUSE, L_I_H_MOUSE, L_1_B_MOUSE,   XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_MOUSE, L_2_T_MOUSE, L_I_T_MOUSE, L_2_B_MOUSE,   XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_MOUSE, L_3_T_MOUSE, L_I_B_MOUSE, L_3_B_MOUSE,   XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_MOUSE, L_4_T_MOUSE, XXXXXXX,     L_4_B_MOUSE,   XXXXXXX,     XXXXXXX,

            /* Down         Inner (pad)  Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_MOUSE, R_T_1_MOUSE, XXXXXXX,     R_T_3_MOUSE,   XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_MOUSE, L_T_1_MOUSE, XXXXXXX,     L_T_3_MOUSE,   XXXXXXX,     XXXXXXX
    ),

    [BUTTON] = LAYOUT(
            /* Center       North        East         South          West         Double-south */
        /*R1*/ R_1_H_BUT,   R_1_T_BUT,   XXXXXXX,     R_1_B_BUT,     R_I_H_BUT,   XXXXXXX,
        /*R2*/ R_2_H_BUT,   R_2_T_BUT,   XXXXXXX,     R_2_B_BUT,     R_I_T_BUT,   XXXXXXX,
        /*R3*/ R_3_H_BUT,   R_3_T_BUT,   XXXXXXX,     R_3_B_BUT,     R_I_B_BUT,   XXXXXXX,
        /*R4*/ R_4_H_BUT,   R_4_T_BUT,   XXXXXXX,     R_4_B_BUT,     XXXXXXX,     XXXXXXX,

        /*L1*/ L_1_H_BUT,   L_1_T_BUT,   L_I_H_BUT,   L_1_B_BUT,     XXXXXXX,     XXXXXXX,
        /*L2*/ L_2_H_BUT,   L_2_T_BUT,   L_I_T_BUT,   L_2_B_BUT,     XXXXXXX,     XXXXXXX,
        /*L3*/ L_3_H_BUT,   L_3_T_BUT,   L_I_B_BUT,   L_3_B_BUT,     XXXXXXX,     XXXXXXX,
        /*L4*/ L_4_H_BUT,   L_4_T_BUT,   XXXXXXX,     L_4_B_BUT,     XXXXXXX,     XXXXXXX,

            /* Down         Inner (pad)  Upper (Mode) O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ R_T_2_BUT,   R_T_1_BUT,   XXXXXXX,     R_T_3_BUT,     XXXXXXX,     XXXXXXX,
        /*LT*/ L_T_2_BUT,   L_T_1_BUT,   XXXXXXX,     L_T_3_BUT,     XXXXXXX,     XXXXXXX
    ),

    [MH_AUTO_BUTTONS_LAYER] = LAYOUT(
            /* Center       North        East                    South          West         Double-south */
        /*R1*/ KC_RSFT,     _______,     _______,                KC_BTN1,       _______,     _______,
        /*R2*/ KC_RCTL,     _______,     _______,                KC_BTN3,       _______,     _______,
        /*R3*/ KC_RALT,     _______,     _______,                KC_BTN2,       _______,     _______,
        /*R4*/ KC_RGUI,     _______,     _______,                _______,       _______,     _______,

        /*L1*/ KC_LSFT,     _______,     SV_RECALIBRATE_POINTER, KC_BTN1,       _______,     _______,
        /*L2*/ KC_LCTL,     _______,     _______,                KC_BTN3,       _______,     _______,
        /*L3*/ KC_LALT,     _______,     _______,                KC_BTN2,       _______,     _______,
        /*L4*/ KC_LGUI,     _______,     _______,                _______,       _______,     _______,
            /* Down         Inner (pad)  Upper (Mode)            O.Upper (nail) OL (knuckle) Pushthrough */
        /*RT*/ _______,     _______,     KC_F24,                 _______,       _______,     _______,
        /*LT*/ _______,     _______,     KC_F24,                 _______,       _______,     _______
        )

};
// clang-format on
