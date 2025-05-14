#include "meteor.h"

static void DrawMeteor(struct Meteor *self);
static void UpdateMeteor(struct Meteor *self, float dt);
static float float_rand( float min, float max );



Meteor *CreateMeteor(int ship)
{
	Meteor *p = malloc(sizeof(Meteor));

	*p = (Meteor) {
		.speed = 300,
		.position = (Vector2) {0},
		.direction = (Vector2) {float_rand(0, 1.0), float_rand(0, 1.0)},
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
	self->position.x += self->direction.x * self->speed * dt;
	self->position.y += self->direction.y * self->speed * dt;
	//Vector2Normalize(self->direction);

}

float float_rand( float min, float max )
{
	float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
	return min + scale * ( max - min );      /* [min, max] */
}
