#ifndef SPACESHIP_SETTINGS
#define SPACESHIP_SETTINGS
#define SCREEN_WIDTH 1920.0
#define SCREEN_HEIGHT 1080.0
#define SCREEN_HCENTER SCREEN_WIDTH / 2
#define SCREEN_VCENTER SCREEN_HEIGHT / 2
#define APP_TITLE "Spaceship Game"
#define BG_COLOR (Color) {10, 10, 25, 255}
#include <raylib.h>

typedef struct Keybindings {
	int player_up;
	int player_down;
	int player_left;
	int player_right;
	int player_shoot;
	int player_special;
	int menu_up;
	int menu_right;
	int menu_left;
	int menu_down;
	int pause_game;
	int exit_game;
	int set_fullscreen;
} Keybindings;
void ConfigWindow(void);
#endif

