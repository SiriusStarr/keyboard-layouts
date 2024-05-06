#include "SiriusStarr.h"
#include "achordion.h"
#include "custom_shift_keys.h"
#include "adaptive_keys.h"
#include "console_key_logger.h"
#include "select_word.h"
#include "macros.h"
#include "sentence_case.h"

#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

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

#if defined(POINTING_DEVICE_AUTO_MOUSE_MH_ENABLE)

#define SCROLL_DIVISOR 20

static int _ds_l_x = 0;
static int _ds_l_y = 0;
static int _ds_r_x = 0;
static int _ds_r_y = 0;

report_mouse_t pointing_device_task_combined_user(report_mouse_t reportMouse1, report_mouse_t reportMouse2) {
  if (reportMouse1.x == 0 && reportMouse1.y == 0 && reportMouse2.x == 0 && reportMouse2.y == 0)
    return pointing_device_combine_reports(reportMouse1, reportMouse2);

  if (global_saved_values.left_scroll) {
    int div_x;
    int div_y;

    _ds_l_x += reportMouse1.x;
    _ds_l_y -= reportMouse1.y;

    div_x = _ds_l_x / SCROLL_DIVISOR;
    div_y = _ds_l_y / SCROLL_DIVISOR;
    if (div_x != 0) {
      reportMouse1.h += div_x;
      _ds_l_x -= div_x * SCROLL_DIVISOR;
    }

    if (div_y != 0) {
      reportMouse1.v += div_y;
      _ds_l_y -= div_y * SCROLL_DIVISOR;
    }
    reportMouse1.x = 0;
    reportMouse1.y = 0;
  }

  if (global_saved_values.right_scroll) {
    int div_x;
    int div_y;

    _ds_r_x += reportMouse2.x;
    _ds_r_y -= reportMouse2.y;

    div_x = _ds_r_x / SCROLL_DIVISOR;
    div_y = _ds_r_y / SCROLL_DIVISOR;
    if (div_x != 0) {
      reportMouse2.h += div_x;
      _ds_r_x -= div_x * SCROLL_DIVISOR;
    }

    if (div_y != 0) {
      reportMouse2.v += div_y;
      _ds_r_y -= div_y * SCROLL_DIVISOR;
    }
    reportMouse2.x = 0;
    reportMouse2.y = 0;
  }

  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    mouse_mode(true);
  }
  return pointing_device_combine_reports(reportMouse1, reportMouse2);
}

report_mouse_t pointing_device_task_user(report_mouse_t reportMouse) {
  if (reportMouse.x == 0 && reportMouse.y == 0)
    return reportMouse;

  if (mh_auto_buttons_timer) {
    mh_auto_buttons_timer = timer_read();
  } else {
    mouse_mode(true);
  }
  return reportMouse;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#if (defined MH_AUTO_BUTTONS && defined PS2_MOUSE_ENABLE && defined MOUSEKEY_ENABLE) || defined(POINTING_DEVICE_AUTO_MOUSE_MH_ENABLE)
  if (mh_auto_buttons_timer) {
    switch (keycode) {
    case KC_BTN1:
    case KC_BTN2:
    case KC_BTN3:
    case KC_BTN4:
    case KC_BTN5:
    case KC_WH_U:
    case KC_WH_D:
    case KC_WH_R:
    case KC_WH_L:
    case KC_LSFT:
    case KC_RSFT:
    case KC_LCTL:
    case KC_RCTL:
    case KC_LALT:
    case KC_RALT:
    case KC_LGUI:
    case KC_RGUI:
    case SV_RECALIBRATE_POINTER:
    case SV_SET_DEADZONE:
      break;
    default:
      mouse_mode(false);
    }
  }
  if (!record->event.pressed) {
    switch (keycode) {
    case SV_LEFT_DPI_INC:
      increase_left_dpi();
      break;
    case SV_LEFT_DPI_DEC:
      decrease_left_dpi();
      break;
    case SV_RIGHT_DPI_INC:
      increase_right_dpi();
      break;
    case SV_RIGHT_DPI_DEC:
      decrease_right_dpi();
      break;
    case SV_LEFT_SCROLL_TOGGLE:
      global_saved_values.left_scroll = !global_saved_values.left_scroll;
      write_eeprom_kb();
      break;
    case SV_RIGHT_SCROLL_TOGGLE:
      global_saved_values.right_scroll = !global_saved_values.right_scroll;
      write_eeprom_kb();
      break;
    case SV_RECALIBRATE_POINTER:
      recalibrate_pointer();
    case SV_SET_DEADZONE:
      PS2_MOUSE_SEND(0x92, "pts: 0x0a");
    default:
      break;
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
