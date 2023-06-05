# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = yes     # Mouse keys
UNICODE_ENABLE = no
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no

AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!

EXTRAKEY_ENABLE = yes    # Audio control and System control
COMBO_ENABLE = yes       # chording
LTO_ENABLE = yes
EXTRAFLAGS += -flto

SRC += SiriusStarr.c

CFLAGS += -fcommon
