#include "settings.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "player.h"
#include "debugging.h"
#include "sprite.h"

int main(void)
{
	ConfigWindow();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE);
	float dt = GetFrameTime();

	Player *p1 = CreatePlayer();
	p1->speed = 300;
	p1->position = (Vector2) {SCREEN_HCENTER, SCREEN_VCENTER};
	p1->drawing_s = (Rectangle) {0};
	p1->hurtbox_s = (Rectangle) {0};
	p1->bullet_cd = 0.5;
	p1->special_cd = 20;
	p1->sprite = CreateSprite(5, &dt);
	LoadSpriteFromDir(p1->sprite, "assets/images/neob2");

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BG_COLOR);
			DrawTexture(p1->sprite->textures[0],
					p1->position.x, p1->position.y, WHITE);
			Debug_Player(p1);
		EndDrawing();
	}

	free(p1->sprite->textures);
	free(p1->sprite);
	free(p1);

	CloseWindow();
}
