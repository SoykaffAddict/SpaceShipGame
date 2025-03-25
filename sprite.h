
#ifndef SPACESHIP_SPRITE
#define SPACESHIP_SPRITE

#include <raylib.h>
typedef struct Sprite {
	int len;
	float anim_index;
	float anim_speed;
	void (*Draw)(struct Sprite *);
	void (*Update)(struct Sprite *, float dt);
	Texture2D *anim;
} Sprite;

Sprite SpriteCreate(int len, Texture2D *textures);
#endif
