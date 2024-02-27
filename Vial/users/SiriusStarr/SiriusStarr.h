#pragma once

#ifndef SIRIUS_STARR
#define SIRIUS_STARR

#include QMK_KEYBOARD_H
#include "layer_names.h"
#include "custom_keycodes.h"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// Macros For Keymap
#define REDO           LSFT(LCTL(KC_Z))
#define PASTE          LCTL(KC_V)
#define COPY           LCTL(KC_C)
#define CUT            LCTL(KC_X)
#define UNDO           LCTL(KC_Z)

#define HOME_C         LGUI_T(KC_C)
#define HOME_S         LALT_T(KC_S)
#define HOME_N         LCTL_T(KC_N)
#define HOME_T         LSFT_T(KC_T)
#define HOME_A         RSFT_T(KC_A)
#define HOME_E         RCTL_T(KC_E)
#define HOME_I         RALT_T(KC_I)
#define HOME_H         RGUI_T(KC_H)

#define P_HOLD_BUT     LT(BUTTON, KC_P)
#define B_HOLD_BUTTON  LT(BUTTON, KC_B)
#define HRM_L_ANG_BRAC RSFT_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define HRM_PIPE       RCTL_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define HRM_MINUS      RALT_T(KC_MINUS)
#define HRM_R_ANG_BRAC RGUI_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define HRM_MSTP       RSFT_T(KC_MSTP)
#define HRM_MPLY       RCTL_T(KC_MPLY)
#define HRM_MUTE       RALT_T(KC_MUTE)
#define COMBO_QU       LT(0, KC_LANGUAGE_9)  // Ugly hack, since LT() only works with basic codes
#define R_HOLD_NAV     LT(NAVIGATION, KC_R)
#define SPACE_HOLD_NAS LT(NUMBER_AND_SYMBOL, KC_SPACE)
#define TAB_HOLD_FUNC  LT(FUNCTION_AND_MEDIA, KC_TAB)
#define ESC_HOLD_MOUSE LT(MOUSE, KC_ESCAPE)

#endif
