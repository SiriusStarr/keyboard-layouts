#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "keymap_combo.h"
#include "layout.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PRIMARY] = LAYOUT(
    L_4_T_BASE, L_3_T_BASE, L_2_T_BASE, L_1_T_BASE, L_I_T_BASE,                         R_I_T_BASE, R_1_T_BASE, R_2_T_BASE, R_3_T_BASE, R_4_T_BASE,
    L_4_H_BASE, L_3_H_BASE, L_2_H_BASE, L_1_H_BASE, L_I_H_BASE,                         R_I_H_BASE, R_1_H_BASE, R_2_H_BASE, R_3_H_BASE, R_4_H_BASE,
    L_4_B_BASE, L_3_B_BASE, L_2_B_BASE, L_1_B_BASE, L_I_B_BASE, XXXXXXX,    XXXXXXX,    R_I_B_BASE, R_1_B_BASE, R_2_B_BASE, R_3_B_BASE, R_4_B_BASE,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    L_T_3_BASE, L_T_1_BASE, L_T_2_BASE, R_T_2_BASE, R_T_1_BASE, R_T_3_BASE, XXXXXXX,    XXXXXXX,    XXXXXXX
  ),

  [NUMBER_AND_SYMBOL] = LAYOUT(
    L_4_T_NAS, L_3_T_NAS, L_2_T_NAS, L_1_T_NAS, L_I_T_NAS,                       R_I_T_NAS, R_1_T_NAS, R_2_T_NAS, R_3_T_NAS, R_4_T_NAS,
    L_4_H_NAS, L_3_H_NAS, L_2_H_NAS, L_1_H_NAS, L_I_H_NAS,                       R_I_H_NAS, R_1_H_NAS, R_2_H_NAS, R_3_H_NAS, R_4_H_NAS,
    L_4_B_NAS, L_3_B_NAS, L_2_B_NAS, L_1_B_NAS, L_I_B_NAS, XXXXXXX,   XXXXXXX,   R_I_B_NAS, R_1_B_NAS, R_2_B_NAS, R_3_B_NAS, R_4_B_NAS,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_NAS, L_T_1_NAS, L_T_2_NAS, R_T_2_NAS, R_T_1_NAS, R_T_3_NAS, XXXXXXX,   XXXXXXX,   XXXXXXX
  ),

  [NAVIGATION] = LAYOUT(
    L_4_T_NAV, L_3_T_NAV, L_2_T_NAV, L_1_T_NAV, L_I_T_NAV,                       R_I_T_NAV, R_1_T_NAV, R_2_T_NAV, R_3_T_NAV, R_4_T_NAV,
    L_4_H_NAV, L_3_H_NAV, L_2_H_NAV, L_1_H_NAV, L_I_H_NAV,                       R_I_H_NAV, R_1_H_NAV, R_2_H_NAV, R_3_H_NAV, R_4_H_NAV,
    L_4_B_NAV, L_3_B_NAV, L_2_B_NAV, L_1_B_NAV, L_I_B_NAV, XXXXXXX,   XXXXXXX,   R_I_B_NAV, R_1_B_NAV, R_2_B_NAV, R_3_B_NAV, R_4_B_NAV,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_NAV, L_T_1_NAV, L_T_2_NAV, R_T_2_NAV, R_T_1_NAV, R_T_3_NAV, XXXXXXX,   XXXXXXX,   XXXXXXX
  ),

  [FUNCTION_AND_MEDIA] = LAYOUT(
    L_4_T_FAM, L_3_T_FAM, L_2_T_FAM, L_1_T_FAM, L_I_T_FAM,                       R_I_T_FAM, R_1_T_FAM, R_2_T_FAM, R_3_T_FAM, R_4_T_FAM,
    L_4_H_FAM, L_3_H_FAM, L_2_H_FAM, L_1_H_FAM, L_I_H_FAM,                       R_I_H_FAM, R_1_H_FAM, R_2_H_FAM, R_3_H_FAM, R_4_H_FAM,
    L_4_B_FAM, L_3_B_FAM, L_2_B_FAM, L_1_B_FAM, L_I_B_FAM, XXXXXXX,   XXXXXXX,   R_I_B_FAM, R_1_B_FAM, R_2_B_FAM, R_3_B_FAM, R_4_B_FAM,
    QK_BOOT,   XXXXXXX,   XXXXXXX,   L_T_3_FAM, L_T_1_FAM, L_T_2_FAM, R_T_2_FAM, R_T_1_FAM, R_T_3_FAM, XXXXXXX,   XXXXXXX,   XXXXXXX
  ),

  [MOUSE] = LAYOUT(
    L_4_T_MOUSE, L_3_T_MOUSE, L_2_T_MOUSE, L_1_T_MOUSE, L_I_T_MOUSE,                           R_I_T_MOUSE, R_1_T_MOUSE, R_2_T_MOUSE, R_3_T_MOUSE, R_4_T_MOUSE,
    L_4_H_MOUSE, L_3_H_MOUSE, L_2_H_MOUSE, L_1_H_MOUSE, L_I_H_MOUSE,                           R_I_H_MOUSE, R_1_H_MOUSE, R_2_H_MOUSE, R_3_H_MOUSE, R_4_H_MOUSE,
    L_4_B_MOUSE, L_3_B_MOUSE, L_2_B_MOUSE, L_1_B_MOUSE, L_I_B_MOUSE, XXXXXXX,     XXXXXXX,     R_I_B_MOUSE, R_1_B_MOUSE, R_2_B_MOUSE, R_3_B_MOUSE, R_4_B_MOUSE,
    XXXXXXX,     XXXXXXX,     XXXXXXX,     L_T_3_MOUSE, L_T_1_MOUSE, L_T_2_MOUSE, R_T_2_MOUSE, R_T_1_MOUSE, R_T_3_MOUSE, XXXXXXX,     XXXXXXX,     XXXXXXX
  ),

  [BUTTON] = LAYOUT(
    L_4_T_BUT, L_3_T_BUT, L_2_T_BUT, L_1_T_BUT, L_I_T_BUT,                       R_I_T_BUT, R_1_T_BUT, R_2_T_BUT, R_3_T_BUT, R_4_T_BUT,
    L_4_H_BUT, L_3_H_BUT, L_2_H_BUT, L_1_H_BUT, L_I_H_BUT,                       R_I_H_BUT, R_1_H_BUT, R_2_H_BUT, R_3_H_BUT, R_4_H_BUT,
    L_4_B_BUT, L_3_B_BUT, L_2_B_BUT, L_1_B_BUT, L_I_B_BUT, XXXXXXX,   XXXXXXX,   R_I_B_BUT, R_1_B_BUT, R_2_B_BUT, R_3_B_BUT, R_4_B_BUT,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_BUT, L_T_1_BUT, L_T_2_BUT, R_T_2_BUT, R_T_1_BUT, R_T_3_BUT, XXXXXXX,   XXXXXXX,   XXXXXXX
  ),
};
// clang-format on
