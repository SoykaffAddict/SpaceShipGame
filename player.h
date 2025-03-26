#include "sprite.h"
#include <raylib.h>

#ifndef SPACESHIP_PLAYER
#define SPACESHIP_PLAYER

typedef struct Bullet {
	int damage;
	Rectangle hitbox;
	Sprite sprite;
	int sprite_len;
	int speed;
} Bullet;

typedef struct Player {
	Vector2 pos;
	Vector2 direction;
	Texture2D texture;
	Color c;
	int speed;
	int lifes;
	void (*Draw)(struct Player *);
	void (*Update)(struct Player *, float dt);
	Bullet *bullets_array;
	int bullets_array_size;
} Player;

Player PlayerCreate(void);
#endif
