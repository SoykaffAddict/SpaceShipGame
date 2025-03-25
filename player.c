#include "player.h"
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include "helpers.h"

static void PlayerDrawF(Player *self)
{
	DrawTexture(self->texture, self->pos.x, self->pos.y, self->c);
}

static void PlayerUpdateF(Player *self, float dt)
{
	self->direction.x = (int) IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	self->direction.y = (int) IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
	self->direction = Vector2Normalize(self->direction);

	self->pos.x += self->direction.x * self->speed * dt;
	self->pos.y += self->direction.y * self->speed * dt;

	if (self->pos.x < 0)
		self->pos.x = 0;
	if (self->pos.y < 0)
		self->pos.y = 0;
	if (self->pos.x + self->texture.width > GetScreenWidth())
		self->pos.x = GetScreenWidth() - self->texture.width;
	if (self->pos.y + self->texture.height > GetScreenHeight())
		self->pos.y = GetScreenHeight() - self->texture.height;
}

Player PlayerCreate(void)
{
	char *player_t_path = Join(3, "assets", "images", "spaceship.png");
	Texture2D player_t = LoadTexture(player_t_path);
	free(player_t_path);

	return (Player) {
		.pos = (Vector2) {0, 0},
		.direction = (Vector2) {0, 0},
		.texture = player_t,
		.c = WHITE,
		.speed = 500,
		.lifes = 0,
		.Draw = PlayerDrawF,
		.Update = PlayerUpdateF,
	};
}
