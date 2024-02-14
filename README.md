# Keyboard Layouts

## Usage

### Vial

```bash
nix develop
vial-qmk compile -kb svalboard/trackpoint/right -km vial
vial-qmk flash -kb svalboard/trackpoint/right -km vial
```

You can then use `Vial` to configure the keyboard.

### QMK

```bash
nix develop
qmk compile -kb <keyboard> -km SiriusStarr
qmk flash -kb <keyboard> -km SiriusStarr
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
keymap draw Layout.yaml > Layout.svg
```

### SVG

![Layout](./Layout.svg)
