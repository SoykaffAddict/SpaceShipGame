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

	Texture2D player_textures[3];
	Sprite sp1 = SpriteCreate(3, player_textures);
	player_textures[0] = LoadTexture("assets/images/explosion/1.png");
	player_textures[1] = LoadTexture("assets/images/explosion/2.png");
	player_textures[2] = LoadTexture("assets/images/explosion/3.png");

	float dt;
	while (!WindowShouldClose()) {
		dt = GetFrameTime();

		p1.Update(&p1, dt);
		sp1.Update(&sp1, dt);
		MappingsUpdate(&DMappings);

		BeginDrawing();
			ClearBackground(BG_COLOR);
			p1.Draw(&p1);
			sp1.Draw(&sp1);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}
