#include "player.h"
#include <stdio.h>

static void DrawPlayer(struct Player *self);
static void UpdatePlayer(struct Player *self);

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
		.Draw = DrawPlayer,
		.Update = UpdatePlayer,
	};

	return p;
}

static void DrawPlayer(struct Player *self)
{
	DrawTexture(self->sprite->textures[(int)self->sprite->actual_f %
		self->sprite->frames_n], self->position.x, self->position.y, 
		WHITE);
}

void UpdatePlayer(struct Player *self)
{
	self->sprite->actual_f += (self->sprite->speed * *self->sprite->dt);
}
