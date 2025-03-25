#include "settings.h"
#include <raylib.h>

bool fullscreen_toggled = true;

void MappingsUpdate(GlobalMappings *self)
{
	if (IsKeyPressed(self->t_fullscreen_key)) {
		int monitor = GetCurrentMonitor();
		SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
		fullscreen_toggled = true;
	}

	if (fullscreen_toggled) {
		ToggleBorderlessWindowed();
		fullscreen_toggled = false;
	}
}

GlobalMappings MappingsCreate(void)
{
	return (GlobalMappings) {
		.t_fullscreen_key = KEY_F,
		.exit_key = KEY_ESCAPE,
	};
}
