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
  case B_HOLD_Q:  // B + U for QU roll.
    if (other_keycode == KC_U) {
      return true;
    }
    break;

  case LT(BUTTON, KC_P):  // Allow BUTTON layer shortcuts
  case LT(BUTTON, KC_QUOTE):
    return true;
  }

  // Also allow same-hand holds for keys a row or more apart
  if (tap_hold_record->event.key.row != other_record->event.key.row) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
