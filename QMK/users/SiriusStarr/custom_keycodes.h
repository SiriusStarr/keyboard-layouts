#ifdef SVALBOARD
#include "keymap_support.h"
#define RANGE_START SV_SAFE_RANGE
#else
#define RANGE_START SAFE_RANGE
#endif

enum custom_keycodes {
  SEL_WORD = RANGE_START,
  COMBO_Z,
  COMBO_WH,
  COMBO_GH,
  COMBO_CH,
  COMBO_SH,
  COMBO_TH,
  COMBO_PH,
  COMBO_PAREN,
  COMBO_BRACE,
  COMBO_BRACK,
  COMBO_A,
  COMBO_I,
};
