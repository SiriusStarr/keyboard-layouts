#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "macros.h"

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

// Helper for digraph combos.
static bool digraph_combo(keyrecord_t *record, uint16_t first_letter, uint16_t second_letter) {
  if (record->event.pressed) {
    if (is_caps_word_on()) {
      add_weak_mods(MOD_BIT(KC_LSFT));
    }
    tap_code16(first_letter);
    unregister_mods(MOD_MASK_SHIFT);
    tap_code16(second_letter);
  }
  return false;
}

bool process_macro_event(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case COMBO_WH:
    return digraph_combo(record, KC_W, KC_H);
  case COMBO_GH:
    return digraph_combo(record, KC_G, KC_H);
  case COMBO_CH:
    return digraph_combo(record, KC_C, KC_H);
  case COMBO_SH:
    return digraph_combo(record, KC_S, KC_H);
  case COMBO_TH:
    return digraph_combo(record, KC_T, KC_H);
  case COMBO_PH:
    return digraph_combo(record, KC_P, KC_H);
  case COMBO_QU:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      if (record->tap.count == 0) {
        tap_code16(KC_Q);
      } else {
        tap_code16(KC_Q);
        unregister_mods(MOD_MASK_SHIFT);
        tap_code16(KC_U);
      }
    }
    return false;
  }

  return true;  // Continue with default handling.
}
