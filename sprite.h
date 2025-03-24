#include <raylib.h>

#ifndef SPACESHIP_SPRITE
#define SPACESHIP_SPRITE
typedef struct Sprite {
	int len;
	float anim_index;
	float anim_speed;
	void (*Draw)(struct Sprite *);
	void (*Update)(struct Sprite *, float dt);
	Texture2D anim[];
} Sprite;

extern Sprite Dsprite;
#endif
