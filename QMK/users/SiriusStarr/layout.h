#include QMK_KEYBOARD_H

// Base Layer
// Top Row
#define L_4_T_BASE KC_W
#define L_3_T_BASE KC_X
#define L_2_T_BASE KC_M
#define L_1_T_BASE KC_G
#define L_I_T_BASE KC_J
#define R_I_T_BASE KC_ASTERISK
#define R_1_T_BASE KC_DOT
#define R_2_T_BASE KC_SLASH
#define R_3_T_BASE KC_DOUBLE_QUOTE
#define R_4_T_BASE KC_QUOTE
// Home Row
#define L_4_H_BASE LGUI_T(KC_C)
#define L_3_H_BASE LALT_T(KC_S)
#define L_2_H_BASE LCTL_T(KC_N)
#define L_1_H_BASE LSFT_T(KC_T)
#define L_I_H_BASE KC_K
#define R_I_H_BASE KC_COMMA
#define R_1_H_BASE RSFT_T(KC_A)
#define R_2_H_BASE RCTL_T(KC_E)
#define R_3_H_BASE RALT_T(KC_I)
#define R_4_H_BASE RGUI_T(KC_H)
// Bottom Row
#define L_4_B_BASE LT(BUTTON, KC_P)
#define L_3_B_BASE KC_F
#define L_2_B_BASE KC_L
#define L_1_B_BASE KC_D
#define L_I_B_BASE KC_V
#define R_I_B_BASE KC_MINUS
#define R_1_B_BASE KC_U
#define R_2_B_BASE KC_O
#define R_3_B_BASE KC_Y
#define R_4_B_BASE LT(BUTTON, KC_B)
// Thumbs
#define L_T_1_BASE LT(NUMBER_AND_SYMBOL, KC_R)
#define L_T_2_BASE KC_BACKSPACE
#define L_T_3_BASE LT(FUNCTION_AND_MEDIA, KC_ESCAPE)
#define R_T_1_BASE LT(NAVIGATION, KC_SPACE)
#define R_T_2_BASE KC_ENTER
#define R_T_3_BASE LT(MOUSE, KC_TAB)


// Number & Symbol Layer
// Top Row
#define L_4_T_NAS KC_PERCENT
#define L_3_T_NAS KC_AT
#define L_2_T_NAS KC_DOLLAR
#define L_1_T_NAS KC_TILDE
#define L_I_T_NAS XXXXXXX
#define R_I_T_NAS XXXXXXX
#define R_1_T_NAS KC_7
#define R_2_T_NAS KC_8
#define R_3_T_NAS KC_9
#define R_4_T_NAS XXXXXXX
// Home Row
#define L_4_H_NAS HRM_L_ANG_BRAC
#define L_3_H_NAS LALT_T(KC_MINUS)
#define L_2_H_NAS HRM_PIPE
#define L_1_H_NAS HRM_R_ANG_BRAC
#define L_I_H_NAS XXXXXXX
#define R_I_H_NAS XXXXXXX
#define R_1_H_NAS RSFT_T(KC_1)
#define R_2_H_NAS RCTL_T(KC_2)
#define R_3_H_NAS RALT_T(KC_5)
#define R_4_H_NAS RGUI_T(KC_0)
// Bottom Row
#define L_4_B_NAS KC_AMPERSAND
#define L_3_B_NAS KC_PLUS
#define L_2_B_NAS KC_EQUAL
#define L_1_B_NAS KC_GRAVE
#define L_I_B_NAS XXXXXXX
#define R_I_B_NAS XXXXXXX
#define R_1_B_NAS KC_3
#define R_2_B_NAS KC_4
#define R_3_B_NAS KC_6
#define R_4_B_NAS XXXXXXX
// Thumbs
#define L_T_1_NAS _______
#define L_T_2_NAS XXXXXXX
#define L_T_3_NAS XXXXXXX
#define R_T_1_NAS KC_DOT
#define R_T_2_NAS KC_COMMA
#define R_T_3_NAS XXXXXXX


// Navigation Layer
// Top Row
#define L_4_T_NAV KC_INSERT
#define L_3_T_NAV KC_CAPS
#define L_2_T_NAV SEL_WORD
#define L_1_T_NAV CW_TOGG
#define L_I_T_NAV XXXXXXX
#define R_I_T_NAV REDO
#define R_1_T_NAV PASTE
#define R_2_T_NAV COPY
#define R_3_T_NAV CUT
#define R_4_T_NAV UNDO
// Home Row
#define L_4_H_NAV KC_LEFT
#define L_3_H_NAV KC_UP
#define L_2_H_NAV KC_DOWN
#define L_1_H_NAV KC_RIGHT
#define L_I_H_NAV XXXXXXX
#define R_I_H_NAV REDO
#define R_1_H_NAV KC_RSFT
#define R_2_H_NAV KC_RCTL
#define R_3_H_NAV KC_RALT
#define R_4_H_NAV KC_RGUI
// Bottom Row
#define L_4_B_NAV KC_HOME
#define L_3_B_NAV KC_PAGE_UP
#define L_2_B_NAV KC_PAGE_DOWN
#define L_1_B_NAV KC_END
#define L_I_B_NAV XXXXXXX
#define R_I_B_NAV REDO
#define R_1_B_NAV PASTE
#define R_2_B_NAV COPY
#define R_3_B_NAV CUT
#define R_4_B_NAV UNDO
// Thumbs
#define L_T_1_NAV KC_R
#define L_T_2_NAV KC_BACKSPACE
#define L_T_3_NAV KC_ESCAPE
#define R_T_1_NAV _______
#define R_T_2_NAV XXXXXXX
#define R_T_3_NAV XXXXXXX


// Function And Media Layer
// Top Row
#define L_4_T_FAM XXXXXXX
#define L_3_T_FAM KC_BRIU
#define L_2_T_FAM KC_BRID
#define L_1_T_FAM XXXXXXX
#define L_I_T_FAM XXXXXXX
#define R_I_T_FAM KC_PSCR
#define R_1_T_FAM KC_F7
#define R_2_T_FAM KC_F8
#define R_3_T_FAM KC_F9
#define R_4_T_FAM KC_F12
// Home Row
#define L_4_H_FAM KC_LGUI
#define L_3_H_FAM LALT_T(KC_MUTE)
#define L_2_H_FAM LCTL_T(KC_MSTP)
#define L_1_H_FAM LSFT_T(KC_MPLY)
#define L_I_H_FAM XXXXXXX
#define R_I_H_FAM KC_SCROLL_LOCK
#define R_1_H_FAM KC_F1
#define R_2_H_FAM KC_F2
#define R_3_H_FAM KC_F5
#define R_4_H_FAM KC_F10
// Bottom Row
#define L_4_B_FAM KC_MPRV
#define L_3_B_FAM KC_VOLU
#define L_2_B_FAM KC_VOLD
#define L_1_B_FAM KC_MNXT
#define L_I_B_FAM XXXXXXX
#define R_I_B_FAM KC_PAUSE
#define R_1_B_FAM KC_F3
#define R_2_B_FAM KC_F4
#define R_3_B_FAM KC_F6
#define R_4_B_FAM KC_F11
// Thumbs
#define L_T_1_FAM XXXXXXX
#define L_T_2_FAM XXXXXXX
#define L_T_3_FAM _______
#define R_T_1_FAM KC_SPACE
#define R_T_2_FAM KC_ENTER
#define R_T_3_FAM KC_TAB


// Mouse Layer
// Top Row
#define L_4_T_MOUSE UNDO
#define L_3_T_MOUSE CUT
#define L_2_T_MOUSE COPY
#define L_1_T_MOUSE PASTE
#define L_I_T_MOUSE REDO
#define R_I_T_MOUSE REDO
#define R_1_T_MOUSE PASTE
#define R_2_T_MOUSE COPY
#define R_3_T_MOUSE CUT
#define R_4_T_MOUSE UNDO
// Home Row
#define L_4_H_MOUSE KC_MS_LEFT
#define L_3_H_MOUSE KC_MS_UP
#define L_2_H_MOUSE KC_MS_DOWN
#define L_1_H_MOUSE KC_MS_RIGHT
#define L_I_H_MOUSE XXXXXXX
#define R_I_H_MOUSE REDO
#define R_1_H_MOUSE KC_RSFT
#define R_2_H_MOUSE KC_RCTL
#define R_3_H_MOUSE KC_RALT
#define R_4_H_MOUSE KC_RGUI
// Bottom Row
#define L_4_B_MOUSE KC_MS_WH_LEFT
#define L_3_B_MOUSE KC_MS_WH_UP
#define L_2_B_MOUSE KC_MS_WH_DOWN
#define L_1_B_MOUSE KC_MS_WH_RIGHT
#define L_I_B_MOUSE XXXXXXX
#define R_I_B_MOUSE REDO
#define R_1_B_MOUSE PASTE
#define R_2_B_MOUSE COPY
#define R_3_B_MOUSE CUT
#define R_4_B_MOUSE UNDO
// Thumbs
#define L_T_1_MOUSE KC_MS_BTN1
#define L_T_2_MOUSE KC_MS_BTN2
#define L_T_3_MOUSE KC_MS_BTN3
#define R_T_1_MOUSE XXXXXXX
#define R_T_2_MOUSE XXXXXXX
#define R_T_3_MOUSE _______


// Button Layer
// Top Row
#define L_4_T_BUT UNDO
#define L_3_T_BUT CUT
#define L_2_T_BUT COPY
#define L_1_T_BUT PASTE
#define L_I_T_BUT REDO
#define R_I_T_BUT REDO
#define R_1_T_BUT PASTE
#define R_2_T_BUT COPY
#define R_3_T_BUT CUT
#define R_4_T_BUT UNDO
// Home Row
#define L_4_H_BUT KC_LGUI
#define L_3_H_BUT KC_LALT
#define L_2_H_BUT KC_LCTL
#define L_1_H_BUT KC_LSFT
#define L_I_H_BUT REDO
#define R_I_H_BUT REDO
#define R_1_H_BUT KC_RSFT
#define R_2_H_BUT KC_RCTL
#define R_3_H_BUT KC_RALT
#define R_4_H_BUT KC_RGUI
// Bottom Row
#define L_4_B_BUT UNDO
#define L_3_B_BUT CUT
#define L_2_B_BUT COPY
#define L_1_B_BUT PASTE
#define L_I_B_BUT REDO
#define R_I_B_BUT REDO
#define R_1_B_BUT PASTE
#define R_2_B_BUT COPY
#define R_3_B_BUT CUT
#define R_4_B_BUT UNDO
// Thumbs
#define L_T_1_BUT KC_MS_BTN1
#define L_T_2_BUT KC_MS_BTN2
#define L_T_3_BUT KC_MS_BTN3
#define R_T_1_BUT KC_MS_BTN1
#define R_T_2_BUT KC_MS_BTN2
#define R_T_3_BUT KC_MS_BTN3
