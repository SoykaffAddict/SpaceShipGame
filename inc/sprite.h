#ifndef SPACESHIP_SPRITE
#define SPACESHIP_SPRITE
#include <raylib.h>

typedef struct Sprite {
	int frames_n;
	int actual_f;
	float speed;
	float *dt;
	Texture2D *textures;
} Sprite;


Sprite *CreateSprite(int frames_n, float *dt);
void LoadSpriteFromDir(Sprite *s, char *dir);
#endif
