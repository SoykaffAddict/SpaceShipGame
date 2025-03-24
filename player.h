#include <raylib.h>

#ifndef SPACESHIP_PLAYER
#define SPACESHIP_PLAYER

typedef struct Player {
	Vector2 pos;
	Vector2 direction;
	Texture2D texture;
	Color c;
	int speed;
	int lifes;
	void (*Draw)(struct Player *);
	void (*Update)(struct Player *, float dt);
} Player;

void PlayerDrawF(Player *self);
void PlayerUpdateF(Player *self, float dt);

extern Player Dplayer;
#endif
