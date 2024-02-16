/*
  Copyright 2018-2022 Eric Gebhart <e.a.gebhart@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined(CONSOLE_ENABLE) && defined(CONSOLE_KEY_LOGGER_ENABLE)

#include "SiriusStarr.h"
#include "print.h"
#include "console_key_logger.h"

void process_console_key_logger(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
            keycode,
            is_combo ? 254 : record->event.key.row,
            is_combo ? 254 : record->event.key.col,
            get_highest_layer(layer_state),
            record->event.pressed,
            get_mods(),
            get_oneshot_mods(),
            record->tap.count);
  }
}
#endif
