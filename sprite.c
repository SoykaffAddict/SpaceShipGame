#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "sprite.h"

/***********************************************************
* SpriteDrawF: Function used as a pointer inside the Sprite*
*              struct to work as a method, draws every     *
*              Texture2D inside the sprite                 *
***********************************************************/
static void SpriteDrawF(struct Sprite *self)
{
	DrawTexture(self->anim[(int)self->anim_index % self->len], 0, 0, WHITE);
}

/*******************************************************************************
* SpriteUpdateF: Function used as a pointer inside the Sprite struct to work as*
*                a method, updates the anim_index variable inside Sprite based *
*                on the speed.                                                 *
********************************************************************************/
static void SpriteUpdateF(struct Sprite *self, float dt)
{
	self->anim_index += (self->anim_speed * dt);
}

Sprite SpriteCreate(int len, Texture2D *textures)
{
	Sprite DSprite = {
		.anim_index = 0,
		.anim_speed = 5,
		.len = len,
		.Draw = SpriteDrawF,
		.Update = SpriteUpdateF,
		.anim = textures,
	};

	return DSprite;
}
