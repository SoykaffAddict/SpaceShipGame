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
	void (*Update)(struct Meteor *self, float dt);
	void (*Draw)(struct Meteor *self);
} Meteor;

Meteor *CreateMeteor(int ship);
#endif
