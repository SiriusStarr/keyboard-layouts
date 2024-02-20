#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>
#include "SiriusStarr.h"
#include "keymap_combo.h"

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
  set_auto_mouse_layer(MBO);
  set_auto_mouse_enable(true);
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIMARY] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ HOME_A,          KC_DOT,          XXXXXXX,        KC_U,           KC_COMMA,
        /*R2*/ HOME_E,          KC_SLASH,        XXXXXXX,        KC_O,           KC_SEMICOLON,
        /*R3*/ HOME_I,          KC_DOUBLE_QUOTE, XXXXXXX,        KC_Y,           KC_MINUS,
        /*R4*/ HOME_H,          KC_QUOTE,        XXXXXXX,        B_HOLD_BUTTON,  COMBO_QU,

        /*L1*/ HOME_T,          KC_G,            KC_K,           KC_D,           XXXXXXX,
        /*L2*/ HOME_N,          KC_M,            KC_J,           KC_L,           XXXXXXX,
        /*L3*/ HOME_S,          KC_X,            KC_V,           KC_F,           XXXXXXX,
        /*L4*/ HOME_C,          KC_W,            KC_Z,           P_HOLD_BUT,  XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_ENTER,        SPACE_HOLD_NAS,  XXXXXXX,        TAB_HOLD_FUNC,  XXXXXXX,     XXXXXXX,
        /*LT*/ KC_BACKSPACE,    R_HOLD_NAV,      XXXXXXX,        ESC_HOLD_MOUSE, XXXXXXX,     XXXXXXX
    ),

    [NUMBER_AND_SYMBOL] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ HRM_L_ANG_BRAC,  KC_DOT,          XXXXXXX,        KC_LBRC,        KC_COMMA,
        /*R2*/ HRM_PIPE,        KC_PLUS,         XXXXXXX,        KC_EQUAL,       XXXXXXX,
        /*R3*/ HRM_MINUS,       KC_HASH,         XXXXXXX,        KC_GRAVE,       XXXXXXX,
        /*R4*/ HRM_R_ANG_BRAC,  XXXXXXX,         XXXXXXX,        KC_ASTERISK,    XXXXXXX,

        /*L1*/ LSFT_T(KC_1),    KC_7,            KC_PERCENT,     KC_3,           XXXXXXX,
        /*L2*/ LCTL_T(KC_2),    KC_8,            XXXXXXX,        KC_4,           XXXXXXX,
        /*L3*/ LALT_T(KC_5),    KC_9,            XXXXXXX,        KC_6,           XXXXXXX,
        /*L4*/ LGUI_T(KC_0),    KC_AMPERSAND,    XXXXXXX,        KC_AT,          XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ XXXXXXX,         _______,         XXXXXXX,        XXXXXXX,        XXXXXXX,     XXXXXXX,
        /*LT*/ KC_TILDE,        KC_LCBR,      XXXXXXX,        KC_DOLLAR,      XXXXXXX,     XXXXXXX
    ),

    [FUNCTION_AND_MEDIA] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ HRM_MSTP,        XXXXXXX,         XXXXXXX,        KC_MPRV,        XXXXXXX,
        /*R2*/ HRM_MPLY,        KC_BRID,         XXXXXXX,        KC_VOLD,        XXXXXXX,
        /*R3*/ HRM_MUTE,        KC_BRIU,         XXXXXXX,        KC_VOLU,        XXXXXXX,
        /*R4*/ KC_RGUI,         XXXXXXX,         XXXXXXX,        KC_MNXT,        XXXXXXX,

        /*L1*/ KC_F1,           KC_F7,           KC_SCROLL_LOCK, KC_F3,          XXXXXXX,
        /*L2*/ KC_F2,           KC_F8,           KC_PSCR,        KC_F4,          XXXXXXX,
        /*L3*/ KC_F5,           KC_F9,           KC_PAUSE,       KC_F6,          XXXXXXX,
        /*L4*/ KC_F10,          KC_F12,          XXXXXXX,        KC_F11,         XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_ENTER,        XXXXXXX,         XXXXXXX,        _______,        XXXXXXX,     XXXXXXX,
        /*LT*/ KC_BACKSPACE,    KC_R,            XXXXXXX,        KC_ESCAPE,      XXXXXXX,     XXXXXXX
    ),

    [NAVIGATION] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ KC_LEFT,         CW_TOGG,         XXXXXXX,        KC_HOME,        KC_CAPS,
        /*R2*/ KC_DOWN,         SEL_WORD,        XXXXXXX,        KC_PAGE_DOWN,   XXXXXXX,
        /*R3*/ KC_UP,           XXXXXXX,         XXXXXXX,        KC_PAGE_UP,     KC_INSERT,
        /*R4*/ KC_RIGHT,        XXXXXXX,         XXXXXXX,        KC_END,         XXXXXXX,

        /*L1*/ KC_LSFT,         XXXXXXX,         REDO,           PASTE,          XXXXXXX,
        /*L2*/ KC_LCTL,         XXXXXXX,         XXXXXXX,        COPY,           XXXXXXX,
        /*L3*/ KC_LALT,         XXXXXXX,         XXXXXXX,        CUT,            XXXXXXX,
        /*L4*/ KC_LGUI,         XXXXXXX,         XXXXXXX,        UNDO,           XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_ENTER,        KC_SPACE,        XXXXXXX,        KC_TAB,         XXXXXXX,     XXXXXXX,
        /*LT*/ XXXXXXX,         _______,         XXXXXXX,        XXXXXXX,        XXXXXXX,     XXXXXXX
    ),

    [MOUSE] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ KC_MS_LEFT,      PASTE,           XXXXXXX,        KC_MS_WH_LEFT,  REDO,
        /*R2*/ KC_MS_DOWN,      COPY,            XXXXXXX,        KC_MS_WH_DOWN,  XXXXXXX,
        /*R3*/ KC_MS_UP,        CUT,             XXXXXXX,        KC_MS_WH_UP,    XXXXXXX,
        /*R4*/ KC_MS_RIGHT,     UNDO,            XXXXXXX,        KC_MS_WH_RIGHT, XXXXXXX,

        /*L1*/ KC_LSFT,         XXXXXXX,         REDO,           PASTE,          XXXXXXX,
        /*L2*/ KC_LCTL,         XXXXXXX,         XXXXXXX,        COPY,           XXXXXXX,
        /*L3*/ KC_LALT,         XXXXXXX,         XXXXXXX,        CUT,            XXXXXXX,
        /*L4*/ KC_LGUI,         XXXXXXX,         XXXXXXX,        UNDO,           XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_MS_BTN2,      KC_MS_BTN1,      XXXXXXX,        KC_MS_BTN3,     XXXXXXX,     XXXXXXX,
        /*LT*/ XXXXXXX,         XXXXXXX,         XXXXXXX,        _______,        XXXXXXX,     XXXXXXX
    ),

    [BUTTON] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ KC_RSFT,         PASTE,           XXXXXXX,        PASTE,          REDO,
        /*R2*/ KC_RCTL,         COPY,            XXXXXXX,        COPY,           XXXXXXX,
        /*R3*/ KC_RALT,         CUT,             XXXXXXX,        CUT,            XXXXXXX,
        /*R4*/ KC_RGUI,         UNDO,            XXXXXXX,        UNDO,           XXXXXXX,

        /*L1*/ KC_LSFT,         PASTE,           REDO,           PASTE,          XXXXXXX,
        /*L2*/ KC_LCTL,         COPY,            XXXXXXX,        COPY,           XXXXXXX,
        /*L3*/ KC_LALT,         CUT,             XXXXXXX,        CUT,            XXXXXXX,
        /*L4*/ KC_LGUI,         UNDO,            XXXXXXX,        UNDO,           XXXXXXX,

             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_MS_BTN2,      KC_MS_BTN1,      XXXXXXX,        KC_MS_BTN3,     XXXXXXX,     XXXXXXX,
        /*LT*/ KC_MS_BTN2,      KC_MS_BTN1,      XXXXXXX,        KC_MS_BTN3,     XXXXXXX,     XXXXXXX
    ),

    [MBO] = LAYOUT(
             /*Center           North            East            South           West*/
        /*R1*/ _______,         _______,         _______,        KC_BTN1,        _______,
        /*R2*/ _______,         _______,         _______,        KC_BTN3,        _______,
        /*R3*/ _______,         _______,         _______,        KC_BTN2,        _______,
        /*R4*/ _______,         _______,         _______,        _______,        _______,
        /*L1*/ _______,         _______,         _______,        KC_BTN1,        _______,
        /*L2*/ _______,         _______,         _______,        KC_BTN3,        _______,
        /*L3*/ _______,         _______,         _______,        KC_BTN2,        _______,
        /*L4*/ _______,         _______,         _______,        _______,        _______,
             /*Down             Inner (pad)      Upper (Mode)    O.Upper (nail)  OL (knuckle) Pushthrough*/
        /*RT*/ KC_MS_BTN2,      KC_MS_BTN1,      XXXXXXX,        KC_MS_BTN3,     XXXXXXX,     XXXXXXX,
        /*LT*/ KC_MS_BTN2,      KC_MS_BTN1,      XXXXXXX,        KC_MS_BTN3,     XXXXXXX,     XXXXXXX
        )

};
// clang-format on
