#include <raylib.h>
#include "settings.h"
#include "sprite.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "player.h"

int main(void)
{
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	GlobalMappings DMappings = MappingsCreate();

	Player p1 = PlayerCreate();

	float dt;
	while (!WindowShouldClose()) {
		dt = GetFrameTime();

		p1.Update(&p1, dt);
		MappingsUpdate(&DMappings);

		BeginDrawing();
			ClearBackground(BG_COLOR);
			p1.Draw(&p1);
		EndDrawing();
	}
	
	free(p1.bullets_array);
	CloseWindow();
	return 0;
}
