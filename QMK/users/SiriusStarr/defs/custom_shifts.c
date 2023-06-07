#include "layer_names.h"
#include "custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {LT(BUTTON, KC_QUOTE), KC_EXCLAIM},           // `'`/`!`
  {KC_DOUBLE_QUOTE, KC_QUESTION},               // `"`/`?`
  {KC_SLASH, KC_BACKSLASH},                     // `/`/`\`
  {LT(MOUSE, KC_BACKSPACE), KC_DELETE},         // `⌫`/`⌦`
  {KC_DOT, KC_LEFT_PAREN},                      // `.`/`(`
  {KC_COMMA, KC_RIGHT_PAREN},                   // `,`/`)`
  {KC_ASTERISK, KC_SLASH},                      // `*`/`/`
  {KC_PLUS, KC_MINUS},                          // `+`/`-`
  {KC_LEFT_PAREN, KC_RIGHT_PAREN},              // `(`/`)`
  {KC_LEFT_BRACKET, KC_RIGHT_BRACKET},          // `[`/`]`
  {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE},  // `{`/`}`
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
  sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
