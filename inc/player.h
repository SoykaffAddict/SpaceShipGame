#ifndef SPACESHIP_PLAYER 
#define SPACESHIP_PLAYER 
#include <raylib.h>
#include "sprite.h"
#include <stdlib.h>

typedef struct Player {
	//ControlsDB *cdb;
	float speed;
	Vector2 position;
	Rectangle drawing_s;
	Rectangle hurtbox_s;
	float bullet_cd;
	float special_cd;
	Sprite *sprite;
	void (*Shoot)(void);
	void (*Special)(void);
	void (*Update)(void);
	void(*Draw)(void);
} Player;

Player *CreatePlayer(void);
#endif
