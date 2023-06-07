#pragma once

#ifndef SIRIUS_STARR
#define SIRIUS_STARR

#include QMK_KEYBOARD_H
#include "layer_names.h"

// Macros For Keymap
#define REDO              LSFT(LCTL(KC_Z))
#define PASTE             LCTL(KC_V)
#define COPY              LCTL(KC_C)
#define CUT               LCTL(KC_X)
#define UNDO              LCTL(KC_Z)

#define HOME_C            GUI_T(KC_C)
#define HOME_S            ALT_T(KC_S)
#define HOME_N            CTL_T(KC_N)
#define HOME_T            SFT_T(KC_T)
#define HOME_A            SFT_T(KC_A)
#define HOME_E            CTL_T(KC_E)
#define HOME_I            ALT_T(KC_I)
#define HOME_H            GUI_T(KC_H)

#define P_HOLD_BUTTON     LT(BUTTON, KC_P)
#define QUOTE_HOLD_BUTTON LT(BUTTON, KC_QUOTE)
#define B_HOLD_Q          LT(0, KC_B)


#endif
