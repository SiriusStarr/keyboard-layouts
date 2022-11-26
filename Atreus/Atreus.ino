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
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
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
  CS_QUOTE_EXCLAMATION,
  CS_DOUBLEQUOTE_QUESTION,
  CS_SLASH_BACKSLASH,
  CS_BACKSPACE_DELETE,
  CS_PERIOD_PARENS,
  CS_COMMA_CLOSE_PARENS,
  CS_ASTERISK_SLASH,
  CS_PLUS_MINUS,
  CS_PARENS_CLOSE,
  CS_BRACKET_CLOSE,
  CS_BRACE_CLOSE,
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)

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

// Macros For Keymap
#define REDO  LSHIFT(LCTRL(Key_Z))
#define PASTE LCTRL(Key_V)
#define COPY  LCTRL(Key_C)
#define CUT   LCTRL(Key_X)
#define UNDO  LCTRL(Key_Z)

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// clang-format off
KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED
  (Key_J,         Key_G,    Key_M,    Key_P,             Key_V,
   GUI_T(R),      ALT_T(S), CTL_T(N), SFT_T(D),          Key_B,
   LT(BUTTON, X), Key_F,    Key_L,    Key_C,             Key_W,             LGUI(Key_R),
   ___,           ___,      ___,      LT(MEDIA, Escape), LT(NAVIGATION, T), CS(CS_BACKSPACE_DELETE),

                     Key_Semicolon,             CS(CS_PERIOD_PARENS), CS(CS_SLASH_BACKSLASH), CS(CS_DOUBLEQUOTE_QUESTION), CS(CS_QUOTE_EXCLAMATION),
                     CS(CS_COMMA_CLOSE_PARENS), SFT_T(A),             CTL_T(E),               ALT_T(I),                    GUI_T(H),
   LGUI(Key_P),       Key_Minus,                 Key_U,                Key_O,                  Key_Y,                       Key_K,
   LT(SYMBOL, Enter), LT(NUMBER, Space),         LT(FUNCTION, Tab),    ___,                    ___,                         ___
  ),

  [NUMBER] = KEYMAP_STACKED
  (LSHIFT(Key_9), Key_7, Key_8, Key_9,             LSHIFT(Key_0),
   Key_0,         Key_1, Key_2, Key_3,             CS(CS_ASTERISK_SLASH),
   XXX,           Key_4, Key_5, Key_6,             LSHIFT(Key_6),         ___,
   ___,           ___,   ___,   CS(CS_PLUS_MINUS), Key_Period,            Key_Equals,

        XXX, XXX,           XXX,             XXX,         XXX,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui,
   ___, XXX, XXX,           XXX,             XXX,         XXX,

   XXX, ___, XXX,           ___,             ___,         ___
   ),

  [SYMBOL] = KEYMAP_STACKED
  (XXX,          LSHIFT(Key_3),        LSHIFT(Key_4),         LSHIFT(Key_5),      XXX,
   Key_Backtick, LSHIFT(Key_Comma),    LSHIFT(Key_Backslash), LSHIFT(Key_Period), XXX,
   XXX,          LSHIFT(Key_Backtick), LSHIFT(Key_2),         LSHIFT(Key_7),      XXX,                 ___,
   ___,          ___,                  ___,                   CS(CS_BRACE_CLOSE), CS(CS_PARENS_CLOSE), CS(CS_BRACKET_CLOSE),

        XXX, XXX,           XXX,             XXX,         XXX,
        XXX, Key_LeftShift, Key_LeftControl, Key_LeftAlt, Key_LeftGui,
   ___, XXX, XXX,           XXX,             XXX,         XXX,
   ___, XXX, XXX,           ___,             ___,         ___
   ),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_F12, Key_F7, Key_F8, Key_F9,     Key_PrintScreen,
   Key_F11, Key_F4, Key_F5, Key_F6,     Key_ScrollLock,
   Key_F10, Key_F1, Key_F2, Key_F3,     Key_Pause,       ___,
   ___,     ___,    ___,    Key_Escape, Key_T,           CS(CS_BACKSPACE_DELETE),

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
  EscapeOneShot,
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys,
  EscapeOneShotConfig,
  LayerNames,
  SpaceCadetConfig,
  OneShotConfig,
  MouseKeysConfig,
  // Enable remapping shifted versions of chars
  CharShift);

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

  // To avoid any surprises, SpaceCadet is turned off by default. However, it
  // can be permanently enabled via Chrysalis, so we should only disable it if
  // no configuration exists.
  SpaceCadetConfig.disableSpaceCadetIfUnconfigured();

  CS_KEYS(
    [CS_QUOTE_EXCLAMATION]    = kaleidoscope::plugin::CharShift::KeyPair(Key_Quote, LSHIFT(Key_1)),                           // `'`/`!`
    [CS_DOUBLEQUOTE_QUESTION] = kaleidoscope::plugin::CharShift::KeyPair(LSHIFT(Key_Quote), LSHIFT(Key_Slash)),               // `"`/`?`
    [CS_SLASH_BACKSLASH]      = kaleidoscope::plugin::CharShift::KeyPair(Key_Slash, Key_Backslash),                           // `/`/`\`
    [CS_BACKSPACE_DELETE]     = kaleidoscope::plugin::CharShift::KeyPair(Key_Backspace, Key_Delete),                          // `⌫`/`⌦`
    [CS_PERIOD_PARENS]        = kaleidoscope::plugin::CharShift::KeyPair(Key_Period, LSHIFT(Key_9)),                          // `.`/`(`
    [CS_COMMA_CLOSE_PARENS]   = kaleidoscope::plugin::CharShift::KeyPair(Key_Comma, LSHIFT(Key_0)),                           // `,`/`)`
    [CS_ASTERISK_SLASH]       = kaleidoscope::plugin::CharShift::KeyPair(LSHIFT(Key_8), Key_Slash),                           // `*`/`/`
    [CS_PLUS_MINUS]           = kaleidoscope::plugin::CharShift::KeyPair(LSHIFT(Key_Equals), Key_Minus),                      // `+`/`-`
    [CS_PARENS_CLOSE]         = kaleidoscope::plugin::CharShift::KeyPair(LSHIFT(Key_9), LSHIFT(Key_0)),                       // `(`/`)`
    [CS_BRACKET_CLOSE]        = kaleidoscope::plugin::CharShift::KeyPair(Key_LeftBracket, Key_RightBracket),                  // `[`/`]`
    [CS_BRACE_CLOSE]          = kaleidoscope::plugin::CharShift::KeyPair(LSHIFT(Key_LeftBracket), LSHIFT(Key_RightBracket)),  // `{`/`}`
  );

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 0), Key_Z),   // Left Pinkie Up/Z
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 11), Key_Q),  // Right Pinkie Down/Q

    // Thumb Layer Shifts (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5), ShiftToLayer(MOUSE)),

    // Pinkie Layer Shift (not a base key, so have to include here)
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 11), ShiftToLayer(BUTTON)), )
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
