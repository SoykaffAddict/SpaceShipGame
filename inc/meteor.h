#ifndef SPACESHIP_METEOR
#define SPACESHIP_METEOR
#include <raylib.h>
#include "keymaps.h"
#include "sprite.h"
#include <stdlib.h>
#include <raymath.h>
#include <time.h>

typedef struct Meteor {
	float speed;
	Vector2 position;
	Vector2 origin;
	Rectangle drawing_s;
	Rectangle hurtbox_s;
	Sprite *sprite;
	Image img;
} Meteor;

bool CreateMeteor(void);
void UpdateMeteor(float dt);
void DrawMeteor(void);
void CleanupMeteor(void);
#endif
