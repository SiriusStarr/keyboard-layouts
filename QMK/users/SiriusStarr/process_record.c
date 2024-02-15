#include "SiriusStarr.h"
#include "achordion.h"
#include "custom_shift_keys.h"
#include "adaptive_keys.h"
#include "console_key_logger.h"
#include "select_word.h"
#include "macros.h"

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

  if (!process_select_word(keycode, record, SEL_WORD)) { return false; }

  if (!process_macro_event(keycode, record)) { return false; }
  return true;
}


void matrix_scan_user(void) {
  achordion_task();
}
