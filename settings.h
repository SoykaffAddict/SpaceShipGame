#ifndef SPACESHIP_SETTINGS

#define SPACESHIP_SETTINGS
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Spaceship"
#define FONT_SIZE 120
#define BG_COLOR (Color) {15, 10, 25, 255}

typedef struct GlobalMappings {
	int t_fullscreen_key;
	int exit_key;
} GlobalMappings;

void MappingsUpdate(GlobalMappings *self);
GlobalMappings MappingsCreate(void);
#endif

