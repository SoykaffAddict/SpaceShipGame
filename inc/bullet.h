#ifndef SPACESHIP_BULLET
#define SPACESHIP_BULLET
#include <raylib.h>
#include "keymaps.h"
#include "sprite.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bullet {
	float speed;
	Vector2 position;
	Rectangle drawing_s;
	Rectangle hurtbox_s;
	Sprite *sprite;
} Bullet;

bool CreateBullet(Vector2 b_pos);
void DrawBullets(void);
void UpdateBullets(float dt);
void CleanupBullets(void);
#endif
