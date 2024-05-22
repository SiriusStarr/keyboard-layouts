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

#define HRM_L_ANG_BRAC LGUI_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define HRM_PIPE       LCTL_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define HRM_R_ANG_BRAC LSFT_T(KC_LANGUAGE_9)  // Ugly hack, since MT() only works with basic codes
#define COMBO_QU       LT(0, KC_LANGUAGE_9)   // Ugly hack, since LT() only works with basic codes

#endif
