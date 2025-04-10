#ifndef SPACESHIP_SPRITE
#define SPACESHIP_SPRITE
#include <raylib.h>

typedef struct Sprite {
	int frames_n;
	float actual_f;
	float speed;
	Texture2D *textures;
} Sprite;


Sprite *CreateSprite(int frames_n);
void LoadSpriteFromDir(Sprite *s, char *dir);
#endif
