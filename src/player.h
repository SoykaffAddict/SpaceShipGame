#ifndef SPACESHIP_PLAYER 
#define SPACESHIP_PLAYER 
#include <raylib.h>
#include <stdlib.h>

typedef struct Player {
	//ControlsDB *cdb;
	float speed;
	Vector2 position;
	Rectangle drawing_s;
	Rectangle hitbox_s;
	float bullet_cd;
	float special_cd;
	void (*Shoot)(void);
	void (*Special)(void);
	void (*Update)(void);
	void(*Draw)(void);
	//Sprite
		//frames_n
		//actual_f
		//speed
		//*dt
		//*textures
} Player;

Player *CreatePlayer(void);
#endif
