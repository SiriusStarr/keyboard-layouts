#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "macros.h"


// Helper for digraph combos.
static bool digraph_combo(keyrecord_t *record, uint16_t first_letter, uint16_t second_letter) {
  if (record->event.pressed) {
    // Fire digraph combos only on base layer
    if (layer_state_cmp(layer_state, PRIMARY)) {
      if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      tap_code16(first_letter);
      unregister_mods(MOD_MASK_SHIFT);
      tap_code16(second_letter);
    }
  }
  return false;
}

// Helper for combos that type something different when shifted.
static bool shift_override_combo(keyrecord_t *record, uint16_t key, uint16_t shifted_key, int first_hold, int second_hold) {
  if (record->event.pressed) {
    // Key overrides don't work for macros, so we have to do this manually
    if (get_mods() & MOD_MASK_SHIFT) {
      uint8_t temp_mods = get_mods();
      unregister_mods(MOD_MASK_SHIFT);  // Turn off shift, since sometimes we want an unshifted key
      tap_code16(shifted_key);
      set_mods(temp_mods);
    } else {
      // No shift, so resolve the combo normally
      tap_code16(key);
    }
  }
  return false;
}

bool process_macro_event(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case COMBO_Z:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      tap_code16(KC_Z);
    }
    return false;
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
  case COMBO_PAREN:
    shift_override_combo(record, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_RSFT, KC_RCTL);
    return false;
  case COMBO_BRACE:
    shift_override_combo(record, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_RCTL, KC_RALT);
    return false;
  case COMBO_BRACK:
    shift_override_combo(record, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_RSFT, KC_RALT);
    return false;
  case COMBO_A:
    if (record->event.pressed) {
      if (layer_state_cmp(layer_state, PRIMARY)) {
        if (is_caps_word_on()) {
          add_weak_mods(MOD_BIT(KC_LSFT));
        }
        tap_code16(KC_SPACE);
        tap_code16(KC_A);
        tap_code16(KC_SPACE);
      }
    }
    return false;
  case COMBO_I:
    if (record->event.pressed) {
      if (layer_state_cmp(layer_state, PRIMARY)) {
        SEND_STRING(" I ");
      }
    }
    return false;
  }

  return true;  // Continue with default handling.
}
