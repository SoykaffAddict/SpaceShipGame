#include <raylib.h>
#include "settings.h"
#include "sprite.h"
#include "timer.h"
#include "helpers.h"
#include <stdlib.h>
#include "player.h"

int main(void)
{
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	Player p1 = Dplayer;
	char *player_texture = Join(3, "assets", "images", "spaceship.png");
	p1.texture = LoadTexture(player_texture);
	free(player_texture);

	p1.speed = 500;

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		p1.Update(&p1, dt);

		BeginDrawing();
		ClearBackground(BLACK);
		p1.Draw(&p1);

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}
