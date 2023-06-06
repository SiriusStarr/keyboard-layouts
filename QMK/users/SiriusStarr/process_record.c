#include "extensions/custom_shift_keys.c"
#include "extensions/adaptive_keys.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool return_state = true;

  // Handle custom-shifted keycodes
  if (!process_custom_shift_keys(keycode, record)) {
    return_state = false;
  }


#ifdef ADAPTIVE_KEYS_ENABLE
  if (!process_adaptive_key(keycode, record)) {
    return_state = false;
  }
#endif

  switch (keycode) {
  // Q linger on B
  case LT(0, KC_B):
    if (!record->tap.count && record->event.pressed) {
      tap_code16(KC_Q);  // Intercept hold function to send Q
      return_state = false;
    }
  }

  return return_state;  // keep processing record
}
