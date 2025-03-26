#include "player.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "sprite.h"

#define SPRITE_LEN 3
#define PATH_SIZE 255
#define B_ARRAY_SIZE 20

static Bullet PlayerBulletCreateF(Player *self);
static void PlayerBulletUpdateF(Player *self, float dt);
static void PlayeBulletDrawF(Player *self);
static void PlayerDrawF(Player *self);
static void PlayerUpdateF(Player *self, float dt);

static Bullet PlayerBulletCreateF(Player *self)
{
	//Load bullet textures for sprite creation
	Texture2D textures[SPRITE_LEN];
	char *bullet_t_path = Join(SPRITE_LEN, "assets", "images", "laser");
	for (int i = 0; i < SPRITE_LEN; i++) {
		char full_path[PATH_SIZE+1];
		snprintf(full_path, PATH_SIZE, "%s%s%d.png", bullet_t_path,
								OS_SEP, i);

		Image img = LoadImage(full_path);
		ImageResize(&img, img.width * 0.20, img.height * 0.20);
		textures[i] = LoadTextureFromImage(img);
	}

	return (Bullet) {
		.damage = 1,
		.hitbox = (Rectangle) {
			// IDK why but it worked, need to improve
			self->pos.x + (float)self->texture.width / 2 -
				(float)textures[0].width / 2,
			self->pos.y - textures[0].height + self->texture.height,
			textures[0].width,
			textures[0].height,
		},
		.sprite = SpriteCreate(SPRITE_LEN, textures),
		.sprite_len = SPRITE_LEN,
		.speed = 500,
	};
}

static void PlayerBulletUpdateF(Player *self, float dt)
{
	//Bullet creation
	if (IsKeyPressed(KEY_SPACE)) {
		for (int i = 0; i < self->bullets_array_size; i++)
			if (self->bullets_array[i].damage != 1) {
				self->bullets_array[i] = PlayerBulletCreateF(self);
			}
				
	}

	//Bullet Movement
	for (int i = 0; i < self->bullets_array_size; i++)
		if (self->bullets_array[i].speed > 0)
			self->bullets_array[i].hitbox.y += -1 * 
				self->bullets_array[i].speed * dt;
	
	//Destroys bullet
	for (int i = 0; i < self->bullets_array_size; i++) {
		if (self->bullets_array[i].hitbox.y < 0 -
				self->bullets_array[i].hitbox.height)
			self->bullets_array[i] = (Bullet) {0};
	}
}

static void PlayeBulletDrawF(Player *self)
{
	for (int i = 0; i < self->bullets_array_size; i++) {
		for (int j = 0; j < self->bullets_array[0].sprite_len; j++)
			DrawTexture(
				self->bullets_array[i].sprite.anim[j], 
				self->bullets_array[i].hitbox.x, 
				self->bullets_array[i].hitbox.y, 
				self->c);
	}
}

static void PlayerDrawF(Player *self)
{
	PlayeBulletDrawF(self);
	DrawTexture(self->texture, self->pos.x, self->pos.y, self->c);
}

static void PlayerUpdateF(Player *self, float dt)
{
	//Check player input
	self->direction.x = (int) IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	self->direction.y = (int) IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
	self->direction = Vector2Normalize(self->direction);

	//Update player positon
	self->pos.x += self->direction.x * self->speed * dt;
	self->pos.y += self->direction.y * self->speed * dt;

	//Check for player screen borders collision
	if (self->pos.x < 0)
		self->pos.x = 0;
	if (self->pos.y < 0)
		self->pos.y = 0;
	if (self->pos.x + self->texture.width > GetScreenWidth())
		self->pos.x = GetScreenWidth() - self->texture.width;
	if (self->pos.y + self->texture.height > GetScreenHeight())
		self->pos.y = GetScreenHeight() - self->texture.height;

	//Bullets are updated inside the player
	PlayerBulletUpdateF(self, dt);
}

Player PlayerCreate(void)
{
	char *player_t_path = Join(3, "assets", "images", "spaceship.png");
	Texture2D player_t = LoadTexture(player_t_path);
	free(player_t_path);

	Bullet *b_array = malloc(sizeof(Bullet) * B_ARRAY_SIZE); //Creates a array for the player shots
	return (Player) {
		.pos = (Vector2) {0, 0},
		.direction = (Vector2) {0, 0},
		.texture = player_t,
		.c = WHITE,
		.speed = 500,
		.lifes = 0,
		.Draw = PlayerDrawF,
		.Update = PlayerUpdateF,
		.bullets_array = b_array,
		.bullets_array_size = B_ARRAY_SIZE,
	};
}
