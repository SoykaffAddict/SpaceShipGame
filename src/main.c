#include "keymaps.h"
#include "settings.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "player.h"
#include "debugging.h"
#include "sprite.h"
#include "keymaps.h"
#include "bullet.h"
#include "meteor.h"
#include "timer.h"

void SpawnMeteor(void)
{
	CreateMeteor();
}

int main(void)
{
	ConfigWindow();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE);
	float dt = 0;

	//NEOB2 setup
	Player *p1 = CreatePlayer(NEOB2);

	//Meteor spawner
	Timer spawn_meteor = CreateTimer();
	spawn_meteor.Activate(&spawn_meteor);
	spawn_meteor.duration = 1;
	spawn_meteor.repeat = true;
	spawn_meteor.func = SpawnMeteor;

	Keymaps *global_keymaps = CreateKeymaps(DEFAULT);
	while (!WindowShouldClose()) {
		dt = GetFrameTime();
		p1->Update(p1, global_keymaps, dt);
		spawn_meteor.Update(&spawn_meteor);
		UpdateMeteor(dt);
		UpdateBullets(dt);

		BeginDrawing();
			ClearBackground(BG_COLOR);
			p1->Draw(p1);
			DrawBullets();
			DrawMeteor();
			Debug_Player(p1);
		EndDrawing();
	}

	free(global_keymaps);
	free(p1->sprite->textures);
	free(p1->sprite);
	free(p1);
	CleanupMeteor();
	CleanupBullets();

	CloseWindow();
}
