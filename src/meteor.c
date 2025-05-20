#include "meteor.h"
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_METEORS 5
#define METEOR_SPEED 300

static Meteor screen_meteors[MAX_METEORS] = {0};

bool CreateMeteor(void)
{
	for (int i = 0; i < MAX_METEORS; i++) {
		if (screen_meteors[i].speed == 0) {
			Meteor m1 = {
				.speed = METEOR_SPEED,
				.position = (Vector2) {0},
				.origin = (Vector2) {0},
				.drawing_s = (Rectangle) {0},
				.hurtbox_s = (Rectangle) {0},
				.sprite = CreateSprite(5),
				.img = LoadImage("assets/images/meteor/meteor.png"),
			};
			m1.sprite->speed = 10;
			ImageResize(&m1.img, m1.img.width * 0.25,
							m1.img.height * 0.25);

			// Set random position for meteor
			SetRandomSeed(time(0));
			int random_axis = GetRandomValue(0, 1);

			if (random_axis) {
				m1.position.x = GetRandomValue(-m1.img.width,
							GetScreenWidth());
				m1.position.y = -m1.img.height;
			} else {
				m1.position.y = GetRandomValue(-m1.img.height,
							GetScreenHeight() / 2);
				m1.position.x = -m1.img.width;
			}

			m1.origin = m1.position;
			screen_meteors[i] = m1;
			return true;
		}
	}
	return false;
}

void DrawMeteor(void)
{
	for (int i = 0; i < MAX_METEORS; i++) {
		Texture2D tex = LoadTextureFromImage(screen_meteors[i].img);
		DrawTextureV(tex, screen_meteors[i].position, WHITE);
	}
}

void UpdateMeteor(float dt)
{
	// Meteor movement
	for (int i = 0; i < MAX_METEORS; i++) {
		Meteor *m = &screen_meteors[i];
		if (m->speed != 0) {
			Vector2 s_center = {
				GetScreenWidth() / 2.0,
				GetScreenHeight() / 2.0
			};
			Vector2 destiny = {
				s_center.x - m->origin.x + s_center.x,
				s_center.y - m->origin.y + s_center.y,
			};

			m->position = Vector2MoveTowards(
				m->position,
				destiny,
				m->speed * dt
			);
			if (m->position.x > GetScreenWidth() * 1.5 ||
				m->position.y >  GetScreenHeight() * 1.5 ||
				m->position.x < GetScreenWidth() * -1.5 ||
				m->position.y < GetScreenHeight() * -1.5) {

				free(m->sprite->textures);
				free(m->sprite);
				*m = (Meteor) {0};
			}
		}
	}
}

void CleanupMeteor(void)
{
	for (int i = 0; i < MAX_METEORS; i++) {
		Meteor *m = &screen_meteors[i];
		if (m->speed != 0) {
			free(m->sprite->textures);
			free(m->sprite);
		}
	}
}
