#include "SiriusStarr.h"
#include "achordion.h"
#include "custom_shift_keys.h"
#include "adaptive_keys.h"

// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(
  keyrecord_t *record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef ADAPTIVE_KEYS_ENABLE
  if (!process_adaptive_key(keycode, record)) {
    return false;
  }
#endif

  if (!process_achordion(keycode, record)) {
    return false;
  }

  // Handle custom-shifted keycodes
  if (!process_custom_shift_keys(keycode, record)) {
    return false;
  }

  switch (keycode) {
  case B_HOLD_Q:  // Comma on tap, Ctrl+C on long press.
    return process_tap_or_long_press_key(record, KC_Q);
  }

  return true;
}


void matrix_scan_user(void) {
  achordion_task();
}
