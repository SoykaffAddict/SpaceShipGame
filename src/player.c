#include "player.h"
#include <stdio.h>
#include <settings.h>

static void DrawPlayer(struct Player *self);
static void UpdatePlayer(struct Player *self, float dt);

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

void UpdatePlayer(struct Player *self, float dt)
{
	self->sprite->actual_f += (self->sprite->speed * dt);
}
