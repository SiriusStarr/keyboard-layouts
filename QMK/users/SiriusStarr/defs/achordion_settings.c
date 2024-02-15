#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "achordion.h"

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t *tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t *other_record) {

  // Consider the following chords as holds
  switch (tap_hold_keycode) {

  case COMBO_QU: // For hold making q not qu
    return true;

  case LT(BUTTON, KC_P): // Allow BUTTON layer shortcuts
  case LT(BUTTON, KC_B):
    return true;
  }

  // Also allow same-hand holds for keys a row or more apart
  if (tap_hold_record->event.key.row != other_record->event.key.row) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
