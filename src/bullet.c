#include "sprite.h"
#include <bullet.h>
#include <raylib.h>
#include <stdbool.h>
#define MAX_BULLETS 20
#define BULLET_SPEED 500
#define BULLET_WIDTH 9
#define BULLET_HEIGHT 54

static Bullet player_bullets[MAX_BULLETS] = {0};

bool CreateBullet(Vector2 b_pos)
{
	b_pos = (Vector2) {b_pos.x - (float)BULLET_WIDTH / 2, b_pos.y -
						(float)BULLET_HEIGHT / 2};
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (player_bullets[i].speed == 0) {
			Bullet b1 = {
				.speed = BULLET_SPEED,
				.drawing_s = (Rectangle) {
					b_pos.x,
					b_pos.y,
					BULLET_WIDTH,
					BULLET_HEIGHT,
				},
				.hurtbox_s = (Rectangle) {
					b_pos.x,
					b_pos.y,
					BULLET_WIDTH,
					BULLET_HEIGHT,
				},
				.sprite = CreateSprite(3),
			};
			b1.sprite->speed = 30;
			LoadSpriteFromDir(b1.sprite, "assets/images/laser");
			player_bullets[i] = b1;
			return true;
		}
	}

	return false;
}

void DrawBullets(void)
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		Bullet *b = &player_bullets[i];
		if (b->speed != 0) {
			DrawTexture(b->sprite->textures[(int)b->sprite->actual_f %
				b->sprite->frames_n], b->hurtbox_s.x, b->hurtbox_s.y, 
				WHITE);
		}
	}
}

void UpdateBullets(float dt)
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		Vector2 direction = {0, -1};
		Bullet *b = &player_bullets[i];
		if (b->speed != 0) {
			b->sprite->actual_f += (b->sprite->speed * dt);
			b->hurtbox_s.x += direction.x * b->speed * dt;
			b->hurtbox_s.y += direction.y * b->speed * dt;
			if (b->hurtbox_s.y < 0 - BULLET_HEIGHT) {
				free(b->sprite->textures);
				free(b->sprite);
				*b = (Bullet) {0};
			}
		}
	}
}

void CleanupBullets(void)
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		Bullet *b = &player_bullets[i];
		if (b->speed != 0) {
			free(b->sprite->textures);
			free(b->sprite);
		}
	}

}
