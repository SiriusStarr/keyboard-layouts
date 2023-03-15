/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018-2022  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-Escape-OneShot.h"
#include "Kaleidoscope-FirmwareVersion.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-LayerNames.h"
#include "Kaleidoscope-CharShift.h"

/** This 'enum' is a list of all the macros used by the Atreus's firmware
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
  (Key_J,         Key_G,    Key_M,    Key_P,             Key_V,
   GUI_T(R),      ALT_T(S), CTL_T(N), SFT_T(D),          Key_B,
   LT(BUTTON, X), Key_F,    Key_L,    Key_C,             Key_W,             LGUI(Key_R),
   ___,           ___,      ___,      LT(MEDIA, Escape), LT(NAVIGATION, T), CS(CS_Backspace_Delete),

                      Key_Semicolon,                 CS(CS_Period_LeftParenthesis), CS(CS_Slash_Backslash), CS(CS_DoubleQuote_Question), CS(CS_Quote_Exclamation),
                      CS(CS_Comma_RightParenthesis), SFT_T(A),                      CTL_T(E),               ALT_T(I),                    GUI_T(H),
   LGUI(Key_P),       Key_Minus,                     Key_U,                         Key_O,                  Key_Y,                       Key_K,
   LT(SYMBOL, Enter), LT(NUMBER, Space),             LT(FUNCTION, Tab),             ___,                    ___,                         ___
  ),

  [NUMBER] = KEYMAP_STACKED
  (Key_LeftParenthesis, Key_7, Key_8, Key_9,             Key_RightParenthesis,
   Key_0,               Key_1, Key_2, Key_3,             CS(CS_Asterisk_Slash),
   XXX,                 Key_4, Key_5, Key_6,             Key_Caret,             ___,
   ___,                 ___,   ___,   CS(CS_Plus_Minus), Key_Period,            Key_Equals,

        XXX, XXX,           XXX,             XXX,         XXX,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui,
   ___, XXX, XXX,           XXX,             XXX,         XXX,

   XXX, ___, XXX,           ___,             ___,         ___
   ),

  [SYMBOL] = KEYMAP_STACKED
  (XXX,          Key_Hash,     Key_Dollar, Key_Percent,           XXX,
   Key_Backtick, Key_LessThan, Key_Pipe,   Key_GreaterThan,       XXX,
   XXX,          Key_Tilde,    Key_At,     Key_And,               XXX,                         ___,
   ___,          ___,          ___,        CS(CS_LeftRightBrace), CS(CS_LeftRightParenthesis), CS(CS_LeftRightBracket),

        XXX, XXX,           XXX,             XXX,         XXX,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui,
   ___, XXX, XXX,           XXX,             XXX,         XXX,
   ___, XXX, XXX,           ___,             ___,         ___
   ),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_F12, Key_F7, Key_F8, Key_F9,     Key_PrintScreen,
   Key_F11, Key_F4, Key_F5, Key_F6,     Key_ScrollLock,
   Key_F10, Key_F1, Key_F2, Key_F3,     Key_Pause,       ___,
   ___,     ___,    ___,    Key_Escape, Key_T,           CS(CS_Backspace_Delete),

        XXX, XXX,           XXX,             XXX,         XXX,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui,
   ___, XXX, XXX,           XXX,             XXX,         XXX,
   XXX, XXX, ___,           ___,             ___,         ___
   ),

  [NAVIGATION] = KEYMAP_STACKED
  (XXX,         XXX,         XXX,             XXX,           XXX,
   Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___,         ___,         ___,             XXX,           ___, XXX,

              REDO,         PASTE,         COPY,          CUT,         UNDO,
              Key_CapsLock, Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow,
   ___,       Key_Insert,   Key_Home,      Key_PageDown,  Key_PageUp,  Key_End,
   Key_Enter, Key_Space,    Key_Tab,       ___,           ___,         ___
   ),

  [MOUSE] = KEYMAP_STACKED
  (XXX,         XXX,         XXX,             XXX,           XXX,
   Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___,         ___,         ___,             XXX,           XXX, ___,

                  REDO,          PASTE,            COPY,              CUT,               UNDO,
                  XXX,           Key_mouseL,       Key_mouseDn,       Key_mouseUp,       Key_mouseR,
   ___,           XXX,           Key_mouseScrollL, Key_mouseScrollDn, Key_mouseScrollUp, Key_mouseScrollR,
   Key_mouseBtnR, Key_mouseBtnL, Key_mouseBtnM,    ___,               ___,               ___
   ),

  [MEDIA] = KEYMAP_STACKED
  (XXX,         XXX,         XXX,             XXX,           XXX,
   Key_LeftGui, Key_LeftAlt, Key_LeftControl, Key_LeftShift, XXX,
   XXX,         XXX,         XXX,             XXX,           XXX, ___,
   ___,         ___,         ___,             ___,           XXX, XXX,

                  XXX,                     XXX,                        Consumer_DisplayBrightnessDecrement, Consumer_DisplayBrightnessIncrement, XXX,
                  XXX,                     Consumer_ScanPreviousTrack, Key_VolumeDown,                      Key_VolumeUp,                        Consumer_ScanNextTrack,
   ___,           XXX,                     XXX,                        XXX,                                 XXX,                                 XXX,
   Consumer_Stop, Consumer_PlaySlashPause, Key_Mute,                   ___,                                 ___,                                 ___
   ),

  [BUTTON] = KEYMAP_STACKED
  (UNDO, CUT, COPY, PASTE,         REDO,
   XXX,  XXX, XXX,  XXX,           XXX,
   UNDO, CUT, COPY, PASTE,         REDO,          ___,
   ___,  ___, ___,  Key_mouseBtnM, Key_mouseBtnL, Key_mouseBtnR,

                  REDO,          PASTE,         COPY, CUT, UNDO,
                  XXX,           XXX,           XXX,  XXX, XXX,
   ___,           REDO,          PASTE,         COPY, CUT, UNDO,
   Key_mouseBtnR, Key_mouseBtnL, Key_mouseBtnM, ___,  ___, ___
   ),
)
// clang-format on

KALEIDOSCOPE_INIT_PLUGINS(
  // ----------------------------------------------------------------------
  // Chrysalis plugins

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

  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  FirmwareVersion,

  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  LayerNames,

  // ----------------------------------------------------------------------
  // Keystroke-handling plugins

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

  // SpaceCadet can turn your shifts into parens on tap, while keeping them as
  // Shifts when held. SpaceCadetConfig lets Chrysalis configure some aspects of
  // the plugin.
  // SpaceCadet,
  // SpaceCadetConfig,

  // Enables the "Sticky" behavior for modifiers, and the "Layer shift when
  // held" functionality for layer keys.
  // OneShot,
  // OneShotConfig,
  // EscapeOneShot,
  // EscapeOneShotConfig,

  // Enable remapping shifted versions of chars
  CharShift,

  // The macros plugin adds support for macros
  Macros,

  // Enables dynamic, Chrysalis-editable macros.
  // DynamicMacros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,
  MouseKeysConfig  //,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  // MagicCombo,

  // Enables the GeminiPR Stenography protocol. Unused by default, but with the
  // plugin enabled, it becomes configurable - and then usable - via Chrysalis.
  // GeminiPR,
);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    default:
      break;
    }
  }
  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  EEPROMKeymap.setup(8);

  LayerNames.reserve_storage(17 * 8);

  Layer.move(EEPROMSettings.default_layer());

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
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 0), Key_Z),   // Left Pinkie Up/Z
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 11), Key_Q),  // Right Pinkie Down/Q

    // Thumb Layer Shifts (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5), ShiftToLayer(MOUSE)),

    // Pinkie Layer Shift (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 11), ShiftToLayer(BUTTON)), )
  Qukeys.setMaxIntervalForTapRepeat(0);  // Disable tap-repeat, since I don't use it and it causes layer misfires on the space key at high speed
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
