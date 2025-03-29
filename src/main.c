#include "settings.h"
#include <raylib.h>

int main(void)
{
	ConfigWindow();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_TITLE);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BG_COLOR);
		EndDrawing();
	}
	CloseWindow();
}
