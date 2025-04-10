#ifndef SPACESHIP_PLAYER 
#define SPACESHIP_PLAYER 
#include <raylib.h>
#include "keymaps.h"
#include "sprite.h"
#include <stdlib.h>

typedef struct Player {
	float speed;
	Vector2 position;
	Rectangle drawing_s;
	Rectangle hurtbox_s;
	float bullet_cd;
	float special_cd;
	Sprite *sprite;
	void (*Shoot)(void);
	void (*Special)(void);
	void (*Update)(struct Player *self, Keymaps *km, float dt);
	void (*Draw)(struct Player *self);
} Player;

enum Spaceships{EMPTY_SHIP, NEOB2, VNANO, LKMETA};

Player *CreatePlayer(int ship);
#endif
