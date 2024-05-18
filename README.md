# Keyboard Layouts

## Usage

### Svalboard (Vial)

```bash
nix develop
# Plug in left side
vial-qmk flash -kb svalboard/left -km SiriusStarr
# Plug in right side
vial-qmk flash -kb svalboard/trackpoint/right -km SiriusStarr
```

For keylogging, set `CONSOLE_ENABLE = yes` in `rules.mk` and uncomment
`#define CONSOLE_KEY_LOGGER_ENABLE` in `config.h`.  On the host computer, run
`./listen_keylogger.sh` to log output to `keylog.csv`.  This data can be
analyzed [here](https://precondition.github.io/qmk-heatmap).

### Atreus (QMK)

```bash
nix develop
qmk flash -kb keyboardio/atreus -km SiriusStarr
```

For keylogging, set `CONSOLE_ENABLE = yes` in `rules.mk` and uncomment
`#define CONSOLE_KEY_LOGGER_ENABLE` in `config.h`.  On the host computer, run
`./listen_keylogger.sh` to log output to `keylog.csv`.  This data can be
analyzed [here](https://precondition.github.io/qmk-heatmap).

### Kaleidoscope

```bash
nix develop
cd <keyboard>
make compile
eeprom-backup.sh
make flash
eeprom-restore.sh
```

## Layout

### Updating

```bash
keymap draw QMK/Layout.yaml > QMK/Layout.svg
keymap draw Kaleidoscope/Layout.yaml > Kaleidoscope/Layout.svg
```

### SVG (Atreus)

![QMK Layout](./QMK/Layout.svg)

### SVG (Svaboard)

![Vial Layout](./Vial/Layout.svg)

### SVG (Kaleidoscope)

![Kaleidoscope Layout](./Kaleidoscope/Layout.svg)
