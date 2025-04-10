#include "keymaps.h"
#include <raylib.h>
#include <stdlib.h>

Keymaps *CreateKeymaps(int preset) {
	Keymaps *km = malloc(sizeof(Keymaps));

	//Implementation needed
	if (preset == CUSTOM) {
	} else if (preset == DEFAULT) {
		*km = (Keymaps) {
			.p_up = KEY_W,
			.p_down = KEY_S,
			.p_left = KEY_A,
			.p_right = KEY_D,
		};
		return km;
	}

	*km = (Keymaps) {
		.p_up = 0,
		.p_down = 0,
		.p_left = 0,
		.p_right = 0,
	};

	return km;
}
