# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = yes     # Mouse keys
UNICODE_ENABLE = no
CONSOLE_ENABLE = no			# Necessary for keylogger
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no

AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!

CAPS_WORD_ENABLE = yes

EXTRAKEY_ENABLE = yes    # Audio control and System control
COMBO_ENABLE = yes       # chording
LTO_ENABLE = yes
EXTRAFLAGS += -flto

# For the combo macros in keymap_combos.h
VPATH += keyboards/gboards/g
VPATH += $(USER_PATH)/defs
VPATH += $(USER_PATH)/extensions

SRC += SiriusStarr.c
SRC += achordion_settings.c
SRC += achordion.c
SRC += custom_shift_keys.c
SRC += adaptive_keys.c
SRC += console_key_logger.c

CFLAGS += -fcommon
