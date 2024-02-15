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
#define REDO                     LSFT(LCTL(KC_Z))
#define PASTE                    LCTL(KC_V)
#define COPY                     LCTL(KC_C)
#define CUT                      LCTL(KC_X)
#define UNDO                     LCTL(KC_Z)

#define HOME_C                   LGUI_T(KC_C)
#define HOME_S                   LALT_T(KC_S)
#define HOME_N                   LCTL_T(KC_N)
#define HOME_T                   LSFT_T(KC_T)
#define HOME_A                   RSFT_T(KC_A)
#define HOME_E                   RCTL_T(KC_E)
#define HOME_I                   RALT_T(KC_I)
#define HOME_H                   RGUI_T(KC_H)

#define P_HOLD_BUTTON            LT(BUTTON, KC_P)
#define B_HOLD_BUTTON            LT(BUTTON, KC_B)
#define HOME_LEFT_ANGLE_BRACKET  RSFT_T(KC_COMMA)
#define HOME_PIPE                RCTL_T(KC_BACKSLASH)
#define HOME_RIGHT_ANGLE_BRACKET RGUI_T(KC_DOT)
#define COMBO_QU                 LT(0, KC_LANGUAGE_9) // Ugly hack, since LT() only works with basic codes

#endif
