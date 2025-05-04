#include <bullet.h>
#include <raylib.h>
#include <stdbool.h>
#define MAX_BULLETS 20
#define BULLET_SPEED 30
#define BULLET_WIDTH 9
#define BULLET_HEIGHT 54

static Bullet player_bullets[MAX_BULLETS] = {0};

bool CreateBullet(Vector2 b_pos)
{
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
				}
			};
			player_bullets[i] = b1;
			return true;
		}
	}

	return false;
}
