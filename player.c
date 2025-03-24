#include "player.h"
#include <raylib.h>
#include <raymath.h>

void PlayerDrawF(Player *self)
{
	DrawTexture(self->texture, self->pos.x, self->pos.y, self->c);
}

void PlayerUpdateF(Player *self, float dt)
{
		self->direction.x = (int) IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
		self->direction.y = (int) IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
		self->direction = Vector2Normalize(self->direction);

		self->pos.x += self->direction.x * self->speed * dt;
		self->pos.y += self->direction.y * self->speed * dt;
}

Player Dplayer = {
	.Draw = PlayerDrawF,
	.Update = PlayerUpdateF,
	.pos = (Vector2) {0, 0},
	.c = WHITE,
	.direction = (Vector2) {0, 0},
	.speed = 0,
	.lifes = 0,
};

