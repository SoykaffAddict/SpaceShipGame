#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>

Sprite *CreateSprite(int frames_n, float *dt) 
{
	Texture2D *textures = malloc(sizeof(Texture2D) * frames_n);
	Sprite *sp1 = malloc(sizeof(Sprite));
	*sp1 = (Sprite) {
		.frames_n = frames_n,
		.actual_f = 0,
		.speed = 0,
		.dt = dt,
		.textures = textures,
	};

	return sp1;
}
