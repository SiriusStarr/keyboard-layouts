#include QMK_KEYBOARD_H
#include "SiriusStarr.h"
#include "keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  *  W     X     M      G      J      ||       ;:    .(     /\     "?    '!
  *  C/GUI S/Alt N/Ctrl T/Shft K      ||       ,)    A/Shft E/Ctrl I/Alt H/GUI
  *  P     F     L      D      V      ||       -_    U      O      Y     B
  *                     Esc    R Bksp || Enter Space Tab
  */
  [PRIMARY] = LAYOUT(
    KC_W,       KC_X,    KC_M,    KC_G,           KC_J,                                 KC_SEMICOLON,   KC_DOT,        KC_SLASH, KC_DOUBLE_QUOTE, KC_QUOTE,
    HOME_C,     HOME_S,  HOME_N,  HOME_T,         KC_K,                                 KC_COMMA,       HOME_A,        HOME_E,   HOME_I,          HOME_H,
    P_HOLD_BUT, KC_F,    KC_L,    KC_D,           KC_V,       LGUI(KC_R),   LGUI(KC_P), KC_MINUS,       KC_U,          KC_O,     KC_Y,            B_HOLD_BUTTON,
    XXXXXXX,    XXXXXXX, XXXXXXX, ESC_HOLD_MOUSE, R_HOLD_NAV, KC_BACKSPACE, KC_ENTER,   SPACE_HOLD_NAS, TAB_HOLD_FUNC, XXXXXXX,  XXXXXXX,         XXXXXXX
  ),

  /*
   *  &     9     8      7            ||      .(     +      #
   *  0/GUI 5/Alt 2/Ctrl 1/Shft %     ||   ,) </Shft |/Ctrl -/Alt >/GUI
   *  @     6     4      3            ||      []     =      `     * /
   *                     $      {} ~^ ||
   */
  [NUMBER_AND_SYMBOL] = LAYOUT(
    KC_AMPERSAND, KC_9,         KC_8,         KC_7,         XXXXXXX,                       XXXXXXX,  KC_DOT,         KC_PLUS,  KC_HASH,   XXXXXXX,
    LGUI_T(KC_0), LALT_T(KC_5), LCTL_T(KC_2), LSFT_T(KC_1), KC_PERCENT,                    KC_COMMA, HRM_L_ANG_BRAC, HRM_PIPE, HRM_MINUS, HRM_R_ANG_BRAC,
    KC_AT,        KC_6,         KC_4,         KC_3,         XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,  KC_LBRC,        KC_EQUAL, KC_GRAVE,  KC_ASTERISK,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_DOLLAR,    KC_LCBR,    KC_TILDE, XXXXXXX, _______,  XXXXXXX,        XXXXXXX,  XXXXXXX,   XXXXXXX
  ),

  /*
   *  F12 F7 F8 F9  PrntScr      ||             BrtnsDown BrtnsUp
   *  F11 F1 F2 F3  ScrlLck      ||   Stop/Shft Play/Ctrl Mute/Alt GUI
   *  F10 F4 F5 F5  Pause        ||   Prev      VolDown   VolUp    Next
   *            Esc R       Bksp ||
   */
  [FUNCTION_AND_MEDIA] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,     KC_PRINT_SCREEN,                        XXXXXXX, XXXXXXX,         KC_BRID,         KC_BRIU,         XXXXXXX,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,     KC_SCROLL_LOCK,                         XXXXXXX, RSFT_T(KC_MSTP), RCTL_T(KC_MPLY), RALT_T(KC_MUTE), KC_RGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,     KC_PAUSE,        XXXXXXX,      XXXXXXX, XXXXXXX, KC_MPRV,         KC_VOLD,         KC_VOLU,         KC_MNXT,
    QK_BOOT, XXXXXXX, XXXXXXX, KC_ESCAPE, KC_R,            KC_BACKSPACE, XXXXXXX, XXXXXXX, _______,         XXXXXXX,         XXXXXXX,         XXXXXXX
  ),

  /*
   *                           ||               CapsWord SelWord/SelSent
   *  GUI  Alt Ctrl Shft       ||       CapsLck Left     Down            Up   Right
   *  Undo Cut Copy Paste Redo ||       Insert  Home     PgDwn           PgUp End
   *                           || Enter Space   Tab
   */
  [NAVIGATION] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,   CW_TOGG, SEL_WORD,     XXXXXXX,    XXXXXXX,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    KC_CAPS, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT,
    UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX,  KC_INSERT,   KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_ENTER, KC_SPACE,  KC_TAB,  XXXXXXX,      XXXXXXX,    XXXXXXX
  ),

  /*
   *                     ||        Redo   Paste     Copy      Cut     Undo
   *  GUI  Alt Ctrl Shft ||               MouseLeft MouseDown MouseUp MouseRight
   *                     ||               WheelLeft WheelDown WheelUp WheelRight
   *  Boot               || RClick LClick MClick
   */
  [MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      REDO,       PASTE,         COPY,          CUT,         UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,    KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3,    XXXXXXX,       XXXXXXX,     XXXXXXX
  ),

  /*
   *  Undo Cut Copy   Paste  Redo   ||        Redo   Paste  Copy Cut Undo
   *  GUI  Alt Ctrl   Shft          ||               Shft   Ctrl Alt GUI
   *  Undo Cut Copy   Paste  Redo   ||        Redo   Paste  Copy Cut Undo
   *           MClick LClick RClick || RClick LClick MClick
   */
  [BUTTON] = LAYOUT(
    UNDO,    CUT,     COPY,    PASTE,      REDO,                               REDO,       PASTE,      COPY,    CUT,     UNDO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,    XXXXXXX,                            XXXXXXX,    KC_RSFT,    KC_RCTL, KC_RALT, KC_RGUI,
    UNDO,    CUT,     COPY,    PASTE,      REDO,       XXXXXXX,    XXXXXXX,    REDO,       PASTE,      COPY,    CUT,     UNDO,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};
// clang-format on
