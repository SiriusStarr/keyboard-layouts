#include "SiriusStarr.h"
#include "achordion.h"
#include "custom_shift_keys.h"
#include "adaptive_keys.h"
#include "console_key_logger.h"
#include "select_word.h"
#include "macros.h"
#include "sentence_case.h"


#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
void mouse_mode(bool);

static uint16_t mh_auto_buttons_timer;
extern int tp_buttons;  // mousekey button state set in action.c and used in ps2_mouse.c

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    if (!tp_buttons) {
      mouse_mode(true);
    }
  }
}

void mouse_mode(bool on) {
  if (on) {
    layer_on(MH_AUTO_BUTTONS_LAYER);
    mh_auto_buttons_timer = timer_read();
  } else {
    layer_off(MH_AUTO_BUTTONS_LAYER);
    mh_auto_buttons_timer = 0;
  }
}

#endif  // defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && #defined MOUSEKEY_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
  if (mh_auto_buttons_timer) {
    switch (keycode) {
    case KC_BTN1:
    case KC_BTN2:
    case KC_BTN3:
    case KC_WH_U:
    case KC_WH_D:
      break;
    default:
      mouse_mode(false);
    }
  }
#endif

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

#if defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE
  if (mh_auto_buttons_timer && (timer_elapsed(mh_auto_buttons_timer) > MH_AUTO_BUTTONS_TIMEOUT)) {
    if (!tp_buttons) {
      mouse_mode(false);
    }
  }
#endif
}
