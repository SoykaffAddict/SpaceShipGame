#include "settings.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef struct Player {
	//ControlsDB *cdb;
	float speed;
	Vector2 position;
	Rectangle drawing_s;
	Rectangle hitbox_s;
	float bullet_cd;
	float special_cd;
	void (*Shoot)(void);
	void (*Special)(void);
	void (*Update)(void);
	void(*Draw)(void);
	//Sprite
		//frames_n
		//actual_f
		//speed
		//*dt
		//*textures
} Player;

Player *CreatePlayer(void);
void Debug_Player(Player *p);

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

void Debug_Player(Player *p)
{
	char current_text[1000+1] = {'\0'};
	char result_text[1000+1] = {'\0'};
	snprintf(current_text, 1000, "speed: %f\n", p->speed);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "position: X:%f  Y:%f\n", p->position.x, 
								p->position.y);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "drawing_s: X:%f  Y:%f  W:%f  H:%f\n", 
		p->drawing_s.x, p->drawing_s.y, p->drawing_s.width, 
		p->drawing_s.height);

	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "hitbox_s: X:%f  Y:%f  W:%f  H:%f\n", 
		p->hitbox_s.x, p->hitbox_s.y, p->hitbox_s.width, 
		p->hitbox_s.height);

	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "bullet_cd: %f\n", p->bullet_cd);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "special_cd: %f\n", p->special_cd);
	strncat(result_text, current_text, 1000);

	DrawText(result_text, 0, 0, 30, WHITE);
}

Player *CreatePlayer(void)
{

	Player *p = malloc(sizeof(Player));
	*p = (Player) {
		.speed = 0,
		.position = (Vector2) {0},
		.drawing_s = (Rectangle) {0},
		.hitbox_s = (Rectangle) {0},
		.bullet_cd = 0,
		.special_cd = 0,
	};

	return p;
}
