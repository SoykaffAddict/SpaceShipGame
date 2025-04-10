#include "keymaps.h"
#include "settings.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "player.h"
#include "debugging.h"
#include "sprite.h"
#include "keymaps.h"

int main(void)
{
	ConfigWindow();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE);
	float dt = 0;

	//NEOB2 setup
	Player *p1 = CreatePlayer(NEOB2);
	Keymaps *global_keymaps = CreateKeymaps(DEFAULT);

	while (!WindowShouldClose()) {
		dt = GetFrameTime();
		p1->Update(p1, global_keymaps, dt);

		BeginDrawing();
			ClearBackground(BG_COLOR);
			p1->Draw(p1);
			Debug_Player(p1);
		EndDrawing();
	}

	free(global_keymaps);
	free(p1->sprite->textures);
	free(p1->sprite);
	free(p1);

	CloseWindow();
}
