#include "meteor.h"
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

static void DrawMeteor(struct Meteor *self);
static void UpdateMeteor(struct Meteor *self, float dt);
static float float_rand( float min, float max );

Meteor *CreateMeteor(int ship)
{
	Meteor *p = malloc(sizeof(Meteor));


	*p = (Meteor) {
		.speed = 300,
		.position = (Vector2) {0},
		.origin = (Vector2) {float_rand(-1, 1.0), float_rand(0, 1.0)},
		.drawing_s = (Rectangle) {0},
		.hurtbox_s = (Rectangle) {0},
		.sprite = CreateSprite(5),
		.img = LoadImage("assets/images/meteor/meteor.png"),
		.Draw = DrawMeteor,
		.Update = UpdateMeteor,
	};
	p->sprite->speed = 10;
	ImageResize(&p->img, p->img.width * 0.25, p->img.height * 0.25);
	//LoadSpriteFromDir(p->sprite, "assets/images/neob2");

	// Set random position for meteor
	SetRandomSeed(time(0));
	int random_axis = GetRandomValue(0, 1);

	if (random_axis) {
		p->position.x = GetRandomValue(-p->img.width,
							GetScreenWidth());
		p->position.y = -p->img.height;
	} else {
		p->position.y = GetRandomValue(-p->img.height,
							GetScreenHeight() / 2);
		p->position.x = -p->img.width;
	}

	p->origin = p->position;
	return p;
}

static void DrawMeteor(struct Meteor *self)
{
	Texture2D tex = LoadTextureFromImage(self->img);
	DrawTextureV(tex, self->position, WHITE);
}

static void UpdateMeteor(struct Meteor *self, float dt)
{
	// Meteor movement
	Vector2 s_center = {GetScreenWidth() / 2.0, GetScreenHeight() / 2.0};
	Vector2 destiny = {
		s_center.x - self->origin.x + s_center.x,
		s_center.y - self->origin.y + s_center.y ,
	};

	self->position = Vector2MoveTowards(self->position, destiny, self->speed * dt);
}

float float_rand( float min, float max )
{
	srand(time(NULL));
	float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
	return min + scale * ( max - min );      /* [min, max] */
}
