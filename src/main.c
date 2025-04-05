#include "settings.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "player.h"
#include "debugging.h"


int main(void)
{
	ConfigWindow();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE);

	Player *p1 = CreatePlayer();
	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BG_COLOR);
			Debug_Player(p1);
		EndDrawing();
	}
	free(p1);
	CloseWindow();
}
