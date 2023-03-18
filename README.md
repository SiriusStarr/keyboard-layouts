# Keyboard Layouts

## Usage

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
