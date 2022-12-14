// -*- mode: c++ -*-
// Copyright 2016-2022 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 100's firmware
 */

// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for querying the firmware version via Focus
#include "Kaleidoscope-FirmwareVersion.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// Support for turning the LEDs off after a certain amount of time
#include "Kaleidoscope-IdleLEDs.h"

// Support for setting and saving the default LED mode
#include "Kaleidoscope-DefaultLEDModeConfig.h"

// Support for changing the brightness of the LEDs
#include "Kaleidoscope-LEDBrightnessConfig.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Support for secondary actions on keys
#include "Kaleidoscope-Qukeys.h"

// Support for dynamic, Chrysalis-editable macros
#include "Kaleidoscope-DynamicMacros.h"

// Support for editable layer names
#include "Kaleidoscope-LayerNames.h"

// Support changing shifted chars
#include "Kaleidoscope-CharShift.h"

/** This 'enum' is a list of all the macros used by the Model 100's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum {
  MACRO_VERSION_INFO,
};

/** This 'enum' is a list of all CharShifted keys.
  */

enum {
  CS_Quote_Exclamation,
  CS_DoubleQuote_Question,
  CS_Slash_Backslash,
  CS_Backspace_Delete,
  CS_Period_LeftParenthesis,
  CS_Comma_RightParenthesis,
  CS_Asterisk_Slash,
  CS_Plus_Minus,
  CS_LeftRightParenthesis,
  CS_LeftRightBracket,
  CS_LeftRightBrace,
};

// Macros For Keymap
#define REDO                 LSHIFT(LCTRL(Key_Z))
#define PASTE                LCTRL(Key_V)
#define COPY                 LCTRL(Key_C)
#define CUT                  LCTRL(Key_X)
#define UNDO                 LCTRL(Key_Z)
#define Key_Exclamation      LSHIFT(Key_1)
#define Key_At               LSHIFT(Key_2)
#define Key_Hash             LSHIFT(Key_3)
#define Key_Dollar           LSHIFT(Key_4)
#define Key_Percent          LSHIFT(Key_5)
#define Key_Caret            LSHIFT(Key_6)
#define Key_And              LSHIFT(Key_7)
#define Key_Asterisk         LSHIFT(Key_8)
#define Key_LeftParenthesis  LSHIFT(Key_9)
#define Key_RightParenthesis LSHIFT(Key_0)
#define Key_LeftBrace        LSHIFT(Key_LeftBracket)
#define Key_RightBrace       LSHIFT(Key_RightBracket)
#define Key_Plus             LSHIFT(Key_Equals)
#define Key_DoubleQuote      LSHIFT(Key_Quote)
#define Key_QuestionMark     LSHIFT(Key_Slash)
#define Key_Pipe             LSHIFT(Key_Backslash)
#define Key_LessThan         LSHIFT(Key_Comma)
#define Key_GreaterThan      LSHIFT(Key_Period)
#define Key_Tilde            LSHIFT(Key_Backtick)

// Colors for the colormap palette
enum {
  C_INACTIVE,
  C_HOMEROW,
  C_HOMING,
  C_BASE,
  C_NUMBER,
  C_SYMBOL,
  C_FUNCTION,
  C_NAVIGATION,
  C_MOUSE,
  C_MEDIA,
  C_BUTTON,
  C_UNUSED_1,
  C_UNUSED_2,
  C_UNUSED_3,
  C_UNUSED_4,
  C_UNUSED_5
};

PALETTE(
  [C_INACTIVE]   = CRGB(0x2e, 0x2e, 0x2e),
  [C_HOMEROW]    = CRGB(0xd6, 0xd6, 0xd6),
  [C_HOMING]     = CRGB(0xff, 0x00, 0x00),
  [C_BASE]       = CRGB(0x79, 0x79, 0x79),
  [C_NUMBER]     = CRGB(0xe5, 0xb5, 0x67),
  [C_SYMBOL]     = CRGB(0xb4, 0xd2, 0x73),
  [C_FUNCTION]   = CRGB(0xb0, 0x00, 0x79),
  [C_NAVIGATION] = CRGB(0x9e, 0x00, 0xc8),
  [C_MOUSE]      = CRGB(0x6c, 0x99, 0xbb),
  [C_MEDIA]      = CRGB(0xe8, 0x7d, 0x00),
  [C_BUTTON]     = CRGB(0x79, 0x79, 0x79),
  [C_UNUSED_1]   = CRGB(0x00, 0x00, 0x00),
  [C_UNUSED_2]   = CRGB(0x00, 0x00, 0x00),
  [C_UNUSED_3]   = CRGB(0x00, 0x00, 0x00),
  [C_UNUSED_4]   = CRGB(0x00, 0x00, 0x00),
  [C_UNUSED_5]   = CRGB(0x00, 0x00, 0x00))

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum {
  PRIMARY,
  NUMBER,
  SYMBOL,
  FUNCTION,
  NAVIGATION,
  MOUSE,
  MEDIA,
  BUTTON,
};  // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// clang-format off

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED
  (___, ___,           ___,      ___,      ___,      ___,   ___,
   ___, Key_J,         Key_G,    Key_M,    Key_P,    Key_V, ___,
   ___, GUI_T(R),      ALT_T(S), CTL_T(N), SFT_T(D), Key_B,
   ___, LT(BUTTON, X), Key_F,    Key_L,    Key_C,    Key_W, ___,

   LT(MEDIA, Escape), LT(NAVIGATION, T), CS(CS_Backspace_Delete), LGUI(Key_R),

   ___,

   ___, ___,                           ___,                           ___,                    ___,                         ___,                      ___,
   ___, Key_Semicolon,                 CS(CS_Period_LeftParenthesis), CS(CS_Slash_Backslash), CS(CS_DoubleQuote_Question), CS(CS_Quote_Exclamation), ___,
        CS(CS_Comma_RightParenthesis), SFT_T(A),                      CTL_T(E),               ALT_T(I),                    GUI_T(H),                 ___,
   ___, Key_Minus,                     Key_U,                         Key_O,                  Key_Y,                       Key_K,                    ___,

   LGUI(Key_P), LT(SYMBOL, Enter), LT(NUMBER, Space), LT(FUNCTION, Tab),

   ___),


  [NUMBER] =  KEYMAP_STACKED
  (___, ___,                 ___,   ___,   ___,   ___,                   ___,
   ___, Key_LeftParenthesis, Key_7, Key_8, Key_9, Key_RightParenthesis,  ___,
   ___, Key_0,               Key_1, Key_2, Key_3, CS(CS_Asterisk_Slash),
   ___, XXX,                 Key_4, Key_5, Key_6, Key_Caret,             ___,

   CS(CS_Plus_Minus), Key_Period, Key_Equals, ___,

   ___,

   ___, ___, ___,           ___,             ___,         ___,         ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui, ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,

   ___, XXX, ___, XXX,

   ___),

  [SYMBOL] =  KEYMAP_STACKED
  (___, ___,          ___,          ___,        ___,             ___, ___,
   ___, XXX,          Key_Hash,     Key_Dollar, Key_Percent,     XXX, ___,
   ___, Key_Backtick, Key_LessThan, Key_Pipe,   Key_GreaterThan, XXX,
   ___, XXX,          Key_Tilde,    Key_At,     Key_And,         XXX, ___,

   CS(CS_LeftRightBrace), CS(CS_LeftRightParenthesis), CS(CS_LeftRightBracket), ___,

   ___,

   ___, ___, ___,           ___,             ___,         ___,         ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui, ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,

   ___, ___, XXX, XXX,

   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (___, ___,     ___,    ___,    ___,    ___,             ___,
   ___, Key_F12, Key_F7, Key_F8, Key_F9, Key_PrintScreen, ___,
   ___, Key_F11, Key_F4, Key_F5, Key_F6, Key_ScrollLock,
   ___, Key_F10, Key_F1, Key_F2, Key_F3, Key_Pause,       ___,

   Key_Escape, Key_T, CS(CS_Backspace_Delete), ___,

   ___,

   ___, ___, ___,           ___,             ___,         ___,         ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui, ___,
   ___, XXX, XXX,           XXX,             XXX,         XXX,         ___,

   ___, XXX, XXX, ___,

   ___),

  [NAVIGATION] = KEYMAP_STACKED
  (___, ___,         ___,         ___,             ___,           ___, ___,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___, Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,

   XXX, ___, XXX, ___,

   ___,

   ___, ___,          ___,            ___,          ___,         ___,            ___,
   ___, REDO,         PASTE,         COPY,          CUT,         UNDO,           ___,
        Key_CapsLock, Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow, ___,
   ___, Key_Insert,   Key_Home,      Key_PageDown,  Key_PageUp,  Key_End,        ___,

   ___, Key_Enter, Key_Space, Key_Tab,

   ___),

  [MOUSE] = KEYMAP_STACKED
  (___, ___,         ___,         ___,             ___,           ___, ___,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___, Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,

   XXX, XXX, ___, ___,

   ___,

   ___, ___,  ___,              ___,               ___,               ___,              ___,
   ___, REDO, PASTE,            COPY,              CUT,               UNDO,             ___,
        XXX,  Key_mouseL,       Key_mouseDn,       Key_mouseUp,       Key_mouseR,       ___,
   ___, XXX,  Key_mouseScrollL, Key_mouseScrollDn, Key_mouseScrollUp, Key_mouseScrollR, ___,

   ___, Key_mouseBtnR, Key_mouseBtnL, Key_mouseBtnM,

   ___),

  [MEDIA] = KEYMAP_STACKED
  (___, ___,         ___,         ___,             ___,           ___, ___,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___, Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   ___, XXX,         XXX,         XXX,             XXX,           XXX, ___,

   ___, XXX, XXX, ___,

   ___,

   ___, ___, ___,                        ___,                                 ___,                                 ___,                    ___,
   ___, XXX, Key_LEDEffectPrevious,      Consumer_DisplayBrightnessDecrement, Consumer_DisplayBrightnessIncrement, Key_LEDEffectNext,      ___,
        XXX, Consumer_ScanPreviousTrack, Key_VolumeDown,                      Key_VolumeUp,                        Consumer_ScanNextTrack, ___,
   ___, XXX, XXX,                        XXX,                                 XXX,                                 XXX,                    ___,

   ___, Consumer_Stop, Consumer_PlaySlashPause, Key_Mute,

   ___),

  [BUTTON] = KEYMAP_STACKED
  (___, ___,  ___, ___,  ___,   ___,  ___,
   ___, UNDO, CUT, COPY, PASTE, REDO, ___,
   ___, XXX,  XXX, XXX,  XXX,   XXX,
   ___, UNDO, CUT, COPY, PASTE, REDO, ___,

   Key_mouseBtnM, Key_mouseBtnL, Key_mouseBtnR, ___,

   ___,

   ___, ___,  ___,   ___,  ___, ___,  ___,
   ___, REDO, PASTE, COPY, CUT, UNDO, ___,
        XXX,  XXX,   XXX,  XXX, XXX,  ___,
   ___, REDO, PASTE, COPY, CUT, UNDO, ___,

   ___, Key_mouseBtnR, Key_mouseBtnL, Key_mouseBtnM,

   ___),
)

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// clang-format off

COLORMAPS(
  [PRIMARY] = COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_INACTIVE,
   C_INACTIVE, C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_HOMING,   C_BASE,
   C_INACTIVE, C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_INACTIVE,

   C_MEDIA, C_NAVIGATION, C_MOUSE, C_BASE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_INACTIVE,
               C_BASE,     C_HOMING,   C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_INACTIVE,
   C_INACTIVE, C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_BASE,     C_INACTIVE,

   C_BASE, C_SYMBOL, C_NUMBER, C_FUNCTION,

   C_INACTIVE),


  [NUMBER] =  COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_NUMBER,   C_NUMBER,   C_NUMBER,   C_NUMBER,   C_NUMBER,   C_INACTIVE,
   C_INACTIVE, C_NUMBER,   C_NUMBER,   C_NUMBER,   C_NUMBER,   C_NUMBER,
   C_INACTIVE, C_INACTIVE, C_NUMBER,   C_NUMBER,   C_NUMBER,   C_NUMBER,   C_INACTIVE,

   C_NUMBER, C_NUMBER, C_NUMBER, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
               C_INACTIVE, C_HOMING,   C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_NUMBER, C_INACTIVE,

   C_INACTIVE),

  [SYMBOL] =  COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_SYMBOL,   C_SYMBOL,   C_SYMBOL,   C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_SYMBOL,   C_SYMBOL,   C_SYMBOL,   C_SYMBOL,   C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_SYMBOL,   C_SYMBOL,   C_SYMBOL,   C_INACTIVE, C_INACTIVE,

   C_SYMBOL, C_SYMBOL, C_SYMBOL, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
               C_INACTIVE, C_HOMING,   C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_SYMBOL, C_INACTIVE, C_INACTIVE,

   C_INACTIVE),

  [FUNCTION] =  COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_INACTIVE,
   C_INACTIVE, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION,
   C_INACTIVE, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_FUNCTION, C_INACTIVE,

   C_BASE, C_BASE, C_BASE, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
               C_INACTIVE, C_HOMING,   C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_FUNCTION,

   C_INACTIVE),

  [NAVIGATION] = COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_HOMING,   C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_NAVIGATION, C_INACTIVE, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE,   C_INACTIVE,   C_INACTIVE,   C_INACTIVE,   C_INACTIVE,   C_INACTIVE,
   C_INACTIVE, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_INACTIVE,
               C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_INACTIVE,
   C_INACTIVE, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_NAVIGATION, C_INACTIVE,

   C_INACTIVE, C_BASE, C_BASE, C_BASE,

   C_INACTIVE),

  [MOUSE] = COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_HOMING,   C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_MOUSE, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_MOUSE,    C_MOUSE,    C_MOUSE,    C_MOUSE,    C_MOUSE,    C_INACTIVE,
               C_INACTIVE, C_MOUSE,    C_MOUSE,    C_MOUSE,    C_MOUSE,    C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_MOUSE,    C_MOUSE,    C_MOUSE,    C_MOUSE,    C_INACTIVE,

   C_INACTIVE, C_MOUSE, C_MOUSE, C_MOUSE,

   C_INACTIVE),

  [MEDIA] = COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_HOMEROW,  C_HOMEROW,  C_HOMEROW,  C_HOMING,   C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_MEDIA, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_MEDIA,    C_MEDIA,    C_MEDIA,    C_MEDIA,    C_INACTIVE,
               C_INACTIVE, C_MEDIA,    C_MEDIA,    C_MEDIA,    C_MEDIA,    C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,

   C_INACTIVE, C_MEDIA, C_MEDIA, C_MEDIA,

   C_INACTIVE),

  [BUTTON] = COLORMAP_STACKED
  (C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_INACTIVE,
   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_INACTIVE,

   C_BUTTON, C_BUTTON, C_BUTTON, C_INACTIVE,

   C_INACTIVE,

   C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_INACTIVE,
               C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE, C_INACTIVE,
   C_INACTIVE, C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_BUTTON,   C_INACTIVE,

   C_INACTIVE, C_BUTTON, C_BUTTON, C_BUTTON,

   C_INACTIVE),
)

/* Re-enable astyle's indent enforcement */
// clang-format on

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t key_state) {
  if (keyToggledOn(key_state)) {
    Macros.type(PSTR("Keyboardio Model 100 - Firmware version "));
    Macros.type(PSTR(KALEIDOSCOPE_FIRMWARE_VERSION));
  }
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  switch (macro_id) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(event.state);
    break;
  }
  return MACRO_NONE;
}


// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 100.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}


/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 * Toggles between using the built-in keymap, and the EEPROM-stored one.
 */
static void toggleKeymapSource(uint8_t combo_index) {
  if (Layer.getKey == Layer.getKeyFromPROGMEM) {
    Layer.getKey = EEPROMKeymap.getKey;
  } else {
    Layer.getKey = Layer.getKeyFromPROGMEM;
  }
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left 1st Thumb  + Esc + Shift
                  .keys = {R0C7, R0C0, R0C6}},
                 {.action = enterHardwareTestMode,
                  // Left 3rd Thumb + Prog + LED
                  .keys = {R2C7, R0C0, R0C6}},
                 {.action = toggleKeymapSource,
                  // Left 4th Thumb + Prog + LED
                  .keys = {R3C7, R0C0, R0C6}});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  LEDRainbowWaveEffect,

  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
  LEDChaseEffect,

  // These static effects turn your keyboard's LEDs a variety of colors
  solidRed,
  solidOrange,
  solidYellow,
  solidGreen,
  solidBlue,
  solidIndigo,
  solidViolet,

  // The breathe effect slowly pulses all of the LEDs on your keyboard
  LEDBreatheEffect,

  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  AlphaSquareEffect,

  // The stalker effect lights up the keys you've pressed recently
  StalkerEffect,

  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  ColormapEffect,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  // The MouseKeysConfig plugin lets Chrysalis configure some aspects of the
  // plugin.
  MouseKeys,
  MouseKeysConfig,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

  // Turns LEDs off after a configurable amount of idle time.
  IdleLEDs,
  PersistentIdleLEDs,

  // Enables dynamic, Chrysalis-editable macros.
  DynamicMacros,

  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  FirmwareVersion,

  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  LayerNames,

  // Enables setting, saving (via Chrysalis), and restoring (on boot) the
  // default LED mode.
  DefaultLEDModeConfig,

  // Enables controlling (and saving) the brightness of the LEDs via Focus.
  LEDBrightnessConfig,

  // Enable remapping shifted versions of chars
  CharShift);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Set the hue of the boot greeting effect to something that will result in a
  // nice green color.
  BootGreetingEffect.hue = 85;

  // We configure the AlphaSquare effect to use RED letters
  AlphaSquare.color = CRGB(255, 0, 0);

  // Set the rainbow effects to be reasonably bright, but low enough
  // to mitigate audible noise in some environments.
  LEDRainbowEffect.brightness(170);
  LEDRainbowWaveEffect.brightness(160);

  // Set the action key the test mode should listen for
  HardwareTestMode.setActionKey(R0C6);

  // The LED Stalker mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  // https://github.com/keyboardio/Kaleidoscope/blob/master/docs/plugins/LED-Stalker.md
  StalkerEffect.variant = STALKER(BlazingTrail);

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for eight layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(8);

  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to eight layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(8);
  DefaultColormap.install();

  // For Dynamic Macros, we need to reserve storage space for the editable
  // macros. A kilobyte is a reasonable default.
  DynamicMacros.reserve_storage(1024);

  // If there's a default layer set in EEPROM, we should set that as the default
  // here.
  Layer.move(EEPROMSettings.default_layer());

  // Editable layer names are stored in EEPROM too, and we reserve 16 bytes per
  // layer for them. We need one extra byte per layer for bookkeeping, so we
  // reserve 17 / layer in total.
  LayerNames.reserve_storage(17 * 8);

  DefaultLEDModeConfig.activateLEDModeIfUnconfigured(&ColormapEffect);

  CS_KEYS(
    [CS_Quote_Exclamation]      = kaleidoscope::plugin::CharShift::KeyPair(Key_Quote, Key_Exclamation),                 // `'`/`!`
    [CS_DoubleQuote_Question]   = kaleidoscope::plugin::CharShift::KeyPair(Key_DoubleQuote, Key_QuestionMark),          // `"`/`?`
    [CS_Slash_Backslash]        = kaleidoscope::plugin::CharShift::KeyPair(Key_Slash, Key_Backslash),                   // `/`/`\`
    [CS_Backspace_Delete]       = kaleidoscope::plugin::CharShift::KeyPair(Key_Backspace, Key_Delete),                  // `⌫`/`⌦`
    [CS_Period_LeftParenthesis] = kaleidoscope::plugin::CharShift::KeyPair(Key_Period, Key_LeftParenthesis),            // `.`/`(`
    [CS_Comma_RightParenthesis] = kaleidoscope::plugin::CharShift::KeyPair(Key_Comma, Key_RightParenthesis),            // `,`/`)`
    [CS_Asterisk_Slash]         = kaleidoscope::plugin::CharShift::KeyPair(Key_Asterisk, Key_Slash),                    // `*`/`/`
    [CS_Plus_Minus]             = kaleidoscope::plugin::CharShift::KeyPair(Key_Plus, Key_Minus),                        // `+`/`-`
    [CS_LeftRightParenthesis]   = kaleidoscope::plugin::CharShift::KeyPair(Key_LeftParenthesis, Key_RightParenthesis),  // `(`/`)`
    [CS_LeftRightBracket]       = kaleidoscope::plugin::CharShift::KeyPair(Key_LeftBracket, Key_RightBracket),          // `[`/`]`
    [CS_LeftRightBrace]         = kaleidoscope::plugin::CharShift::KeyPair(Key_LeftBrace, Key_RightBrace),              // `{`/`}`
  );

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 1), Key_Z),   // Left Pinkie Up/Z
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 14), Key_Q),  // Right Pinkie Down/Q

    // Thumb Layer Shifts (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), ShiftToLayer(MOUSE)),

    // Pinkie Layer Shift (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 14), ShiftToLayer(BUTTON)), )
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
