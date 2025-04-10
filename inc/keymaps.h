#ifndef SPACESHIP_KEYMAPS
#define SPACESHIP_KEYMAPS
#include <raylib.h>
#include "sprite.h"
#include <stdlib.h>

typedef struct Keymaps {
	int p_up;
	int p_down;
	int p_left;
	int p_right;
} Keymaps;

enum keymap_presets {EMPTY_KEYMAPS, DEFAULT, CUSTOM};

Keymaps *CreateKeymaps(int preset);
#endif
