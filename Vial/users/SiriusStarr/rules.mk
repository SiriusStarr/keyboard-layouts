# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = yes     # Mouse keys
UNICODE_ENABLE = no
CONSOLE_ENABLE = no			# Necessary for keylogger
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = yes	# For custom shifts; if tight on firmware space, can use https://getreuer.info/posts/keyboards/custom-shift-keys/index.html insted, as it's smaller.

AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!

CAPS_WORD_ENABLE = yes

EXTRAKEY_ENABLE = yes    # Audio control and System control
COMBO_ENABLE = yes       # chording

# Svalboard compiling breaks with LTO
# LTO_ENABLE = yes
# EXTRAFLAGS += -flto

# For the combo macros in keymap_combos.h
VPATH += keyboards/gboards/g
VPATH += $(USER_PATH)/defs
VPATH += $(USER_PATH)/extensions
# For keymap_support.c
VPATH += keyboards/svalboard/keymaps

SRC += SiriusStarr.c
SRC += achordion_settings.c
SRC += achordion.c
SRC += custom_shift_keys.c
SRC += adaptive_keys.c
SRC += console_key_logger.c
SRC += select_word.c
SRC += macros.c
SRC += sentence_case.c
SRC += keymap_support.c

CFLAGS += -fcommon
