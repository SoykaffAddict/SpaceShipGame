#include "player.h"

Player *CreatePlayer(void)
{
	Player *p = malloc(sizeof(Player));
	*p = (Player) {
		.speed = 0,
		.position = (Vector2) {0},
		.drawing_s = (Rectangle) {0},
		.hurtbox_s = (Rectangle) {0},
		.bullet_cd = 0,
		.special_cd = 0,
	};

	return p;
}
