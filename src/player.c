#include "player.h"
#include <raylib.h>
#include <stdio.h>
#include <settings.h>
#include <raymath.h>
#include "bullet.h"

static void DrawPlayer(struct Player *self);
static void UpdatePlayer(struct Player *self, Keymaps *km, float dt);

Player *CreatePlayer(int ship)
{
	Player *p = malloc(sizeof(Player));

	if (ship == NEOB2) {
		*p = (Player) {
			.speed = 300,
			.position = (Vector2) {SCREEN_HCENTER, SCREEN_VCENTER},
			.drawing_s = (Rectangle) {0},
			.hurtbox_s = (Rectangle) {0},
			.bullet_cd = 0.5,
			.special_cd = 20,
			.sprite = CreateSprite(5),
			.Draw = DrawPlayer,
			.Update = UpdatePlayer,
		};
		p->sprite->speed = 10;
		LoadSpriteFromDir(p->sprite, "assets/images/neob2");

		return p;
	}

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

void UpdatePlayer(struct Player *self, Keymaps *km, float dt)
{
	// Update Sprite frame
	self->sprite->actual_f += (self->sprite->speed * dt);
	
	// Player movement
	Vector2 direction = {0};
	direction.x = (int) IsKeyDown(km->p_right) - IsKeyDown(km->p_left);
	direction.y = (int) IsKeyDown(km->p_down) - IsKeyDown(km->p_up);
	Vector2Normalize(direction);
	self->position.x += direction.x * self->speed * dt;
	self->position.y += direction.y * self->speed * dt;

	// Shoot
	if (IsKeyPressed(km->shoot)) {
		Vector2 player_hcenter = {self->position.x + (float) 
			self->sprite->textures->width / 2, self->position.y};
		CreateBullet(player_hcenter);
	}
}
