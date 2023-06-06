#include QMK_KEYBOARD_H

#include "SiriusStarr.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  *  W     X     M      G      J      ||       ;:    .(     /\     "?    '!
  *  C/GUI S/Alt N/Ctrl T/Shft K      ||       ,)    A/Shft E/Ctrl I/Alt H/GUI
  *  P     F     L      D      V      ||       -_     U     O      Y     B
  *                     Esc    R Bksp || Enter Space Tab
  */
  [PRIMARY] = LAYOUT(
    KC_W,             KC_X,        KC_M,        KC_G,                 KC_J,                                                                KC_SEMICOLON,         KC_DOT,               KC_SLASH,    KC_DOUBLE_QUOTE, KC_QUOTE,
    GUI_T(KC_C),      ALT_T(KC_S), CTL_T(KC_N), SFT_T(KC_T),          KC_K,                                                                KC_COMMA,             SFT_T(KC_A),          CTL_T(KC_E), ALT_T(KC_I),     GUI_T(KC_H),
    LT(BUTTON, KC_P), KC_F,        KC_L,        KC_D,                 KC_V,                 LGUI(KC_R),              LGUI(KC_P),           KC_MINUS,             KC_U,                 KC_O,        KC_Y,            LT(0,KC_B),
    XXXXXXX,          XXXXXXX,     XXXXXXX,     LT(MEDIA, KC_ESCAPE), LT(NAVIGATION, KC_R), LT(MOUSE, KC_BACKSPACE), LT(SYMBOL, KC_ENTER), LT(NUMBER, KC_SPACE), LT(FUNCTION, KC_TAB), XXXXXXX,     XXXXXXX,         XXXXXXX
  ),

  /*
   *  ( 7 8 9  )     ||
   *  0 1 2 3  * /   ||     Shft Ctrl Alt GUI
   *    4 5 6  ^     ||
   *        +- .   = ||
   */
  [NUMBER] = LAYOUT(
    KC_LEFT_PAREN, KC_7,    KC_8,    KC_9,    KC_RIGHT_PAREN,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_0,          KC_1,    KC_2,    KC_3,    KC_ASTERISK,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    XXXXXXX,       KC_4,    KC_5,    KC_6,    KC_CIRCUMFLEX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,       XXXXXXX, XXXXXXX, KC_PLUS, KC_DOT,         KC_EQUAL, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /*
   *    # $ %       ||
   *  ` < | >       ||     Shft Ctrl Alt GUI
   *    ~ @ &       ||
   *        {} () []||
   */
  [SYMBOL] = LAYOUT(
    XXXXXXX,  KC_HASH,               KC_DOLLAR, KC_PERCENT,             XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_GRAVE, KC_LEFT_ANGLE_BRACKET, KC_PIPE,   KC_RIGHT_ANGLE_BRACKET, XXXXXXX,                                 XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    XXXXXXX,  KC_TILDE,              KC_AT,     KC_AMPERSAND,           XXXXXXX,       XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,               XXXXXXX,   KC_LEFT_CURLY_BRACE,    KC_LEFT_PAREN, KC_LEFT_BRACKET, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /*
   *  F12 F7 F8 F9  PrntScr      ||
   *  F11 F1 F2 F3  ScrlLck      ||     Shft Ctrl Alt GUI
   *  F10 F4 F5 F5  Pause        ||
   *            Esc R       Bksp ||
   */
  [FUNCTION] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,     KC_PRINT_SCREEN,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,     KC_SCROLL_LOCK,                         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,     KC_PAUSE,        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESCAPE, KC_R,            KC_BACKSPACE, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /*
   *                    ||       Redo    Paste Copy  Cut  Undo
   *  GUI Alt Ctrl Shft ||       CapsLck Left  Down  Up   Right
   *                    ||       Insert  Home  PgDwn PgUp End
   *                    || Enter Space   Tab
   */
  [NAVIGATION] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    REDO,         PASTE,   COPY,         CUT,        UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    KC_CAPS_LOCK, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INSERT,    KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_ENTER, KC_SPACE,     KC_TAB,  XXXXXXX,      XXXXXXX,    XXXXXXX
  ),

  /*
   *                    ||        Redo   Paste     Copy      Cut     Undo
   *  GUI Alt Ctrl Shft ||               MouseLeft MouseDown MouseUp MouseRight
   *                    ||               WheelLeft WheelDown WheelUp WheelRight
   *                    || RClick LClick MClick
   */
  [MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      REDO,       PASTE,         COPY,          CUT,         UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,    KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3,    XXXXXXX,       XXXXXXX,     XXXXXXX
  ),

  /*
   *                    ||      RGBTog RGBMod RGBHue  RGBSat RGBVal
   *  GUI Alt Ctrl Shft ||             Prev   VolDown VolUp  Next
   *                    ||      OutTog
   *                    || Stop Play   Mute
   */
  [MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OU_AUTO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /*
   *  Undo Cut Copy   Paste  Redo   ||        Redo   Paste  Copy Cut Undo
   *  GUI  Alt Ctrl   Shft          ||               Shft   Ctrl Alt GUI
   *  Undo Cut Copy   Paste  Redo   ||        Redo   Paste  Copy Cut Undo
   *           MClick LClick RClick || RClick LClick MClick
   */
  [BUTTON] = LAYOUT(
    UNDO,    CUT,     COPY,    PASTE,      REDO,                               REDO,       PASTE,      COPY,    CUT,     UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    XXXXXXX,                            XXXXXXX,    KC_LSFT,    KC_LCTL, KC_LALT, KC_LGUI,
    UNDO,    CUT,     COPY,    PASTE,      REDO,       XXXXXXX,    XXXXXXX,    REDO,       PASTE,      COPY,    CUT,     UNDO,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
// clang-format on
