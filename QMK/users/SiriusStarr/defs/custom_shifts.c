#include "layer_names.h"
#include "custom_shift_keys.h"

#ifdef CUSTOM_SHIFT_KEYS_ENABLE

const custom_shift_key_t custom_shift_keys[] = {
  // Base Layer
  {KC_QUOTE, KC_EXCLAIM},                       // `'`/`!`
  {KC_DOUBLE_QUOTE, KC_QUESTION},               // `"`/`?`
  {KC_SLASH, KC_BACKSLASH},                     // `/`/`\`
  {KC_DOT, KC_COLON},                           // `.`/`:`
  {KC_ASTERISK, KC_HASH},                       // `*`/`#`
  {KC_COMMA, KC_SEMICOLON},                     // `,`/`;`
  {KC_LEFT_PAREN, KC_RIGHT_PAREN},              // `(`/`)`
  {KC_LEFT_BRACKET, KC_RIGHT_BRACKET},          // `[`/`]`
  {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE},  // `{`/`}`
  {KC_BACKSPACE, KC_DELETE},                    // `⌫`/`⌦`
  // Number And Symbol Layer
  {KC_TILDE, KC_CIRCUMFLEX},  // `~`/`^`
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
  sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#else

// Base Layer
const key_override_t quote_exclaim_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_EXCLAIM);  // `'`/`!`
const key_override_t double_quote_question_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUESTION);  // `"`/`?`
const key_override_t slash_backslash_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH);  // `/`/`\`
const key_override_t period_colon_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);  // `.`/`:`
const key_override_t comma_semicolon_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);  // `,`/`)`
const key_override_t asterisk_hash_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_HASH);  // `*`/`#`
const key_override_t backspace_delete_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE);  // `⌫`/`⌦`
// Number And Symbol Layer
const key_override_t left_right_parenthesis_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);  // `(`/`)`
const key_override_t left_right_bracket_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_BRACKET, KC_RIGHT_BRACKET);  // `[`/`]`
const key_override_t left_right_curly_brace_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);  // `{`/`}`
const key_override_t tilde_circumflex_override =
  ko_make_basic(MOD_MASK_SHIFT, KC_TILDE, KC_CIRCUMFLEX);  // `~`/`^`

const key_override_t **key_overrides = (const key_override_t *[]){
  // Base Layer
  &quote_exclaim_override,
  &double_quote_question_override,
  &slash_backslash_override,
  &period_colon_override,
  &comma_semicolon_override,
  &asterisk_hash_override,
  &left_right_parenthesis_override,
  &left_right_bracket_override,
  &left_right_curly_brace_override,
  &backspace_delete_override,
  // Number And Symbol Layer
  &tilde_circumflex_override,
  NULL};

#endif
