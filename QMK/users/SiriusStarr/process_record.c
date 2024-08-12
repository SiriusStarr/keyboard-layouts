#include "SiriusStarr.h"
#include "achordion.h"
#include "custom_shift_keys.h"
#include "adaptive_keys.h"
#include "console_key_logger.h"
#include "select_word.h"
#include "macros.h"
#include "sentence_case.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef ADAPTIVE_KEYS_ENABLE
  if (!process_adaptive_key(keycode, record)) {
    return false;
  }
#endif

  if (!process_achordion(keycode, record)) {
    return false;
  }

#ifdef CUSTOM_SHIFT_KEYS_ENABLE
  // Handle custom-shifted keycodes
  if (!process_custom_shift_keys(keycode, record)) {
    return false;
  }
#endif

#if defined(CONSOLE_ENABLE) && defined(CONSOLE_KEY_LOGGER_ENABLE)
  process_console_key_logger(keycode, record);
#endif

  if (!process_select_word(keycode, record, SEL_WORD)) {
    return false;
  }

#ifdef SENTENCE_CASE_ENABLE
  if (!process_sentence_case(keycode, record)) {
    return false;
  }
#endif

  if (!process_macro_event(keycode, record)) {
    return false;
  }

  // Handle MT's for non-basic keys
  if (record->tap.count != 0) {  // Key is being held.
    if (record->event.pressed) {
      switch (keycode) {
      case HRM_L_ANG_BRAC:
        tap_code16(KC_LEFT_ANGLE_BRACKET);
        return false;
      case HRM_PIPE:
        tap_code16(KC_PIPE);
        return false;
      case HRM_R_ANG_BRAC:
        tap_code16(KC_RIGHT_ANGLE_BRACKET);
        return false;
      }
    }
  }
  return true;
}


void matrix_scan_user(void) {
  achordion_task();
}

void keyboard_post_init_user(void) {
#ifdef SVALBOARD
  global_saved_values.mh_timer_index  = 1;  // Set mousekeys timer to 500 ms.
  global_saved_values.left_scroll     = 1;  // Set left pointer to scroll
  global_saved_values.right_dpi_index = 5;  // Set right pointer DPI to 2400
#endif
}


bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  // This is taken from https://docs.qmk.fm/features/combo
  // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
  uint16_t key;
  uint8_t idx = 0;
  while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
    switch (key) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      return true;
    }
    idx += 1;
  }
  return false;
}
