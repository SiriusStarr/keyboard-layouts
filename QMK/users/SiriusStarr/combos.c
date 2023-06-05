const uint16_t PROGMEM combo_z[] = {KC_W, KC_X, COMBO_END};  // W+X -> Z
const uint16_t PROGMEM combo_q[] = {KC_X, KC_G, COMBO_END};  // X+G -> Q

combo_t key_combos[] = {
  COMBO(combo_z, KC_Z),
  COMBO(combo_q, KC_Q),
};
