#ifndef SPACESHIP_TIMER
#define SPACESHIP_TIMER
#include <stdbool.h>
#include <raylib.h>
#include <time.h>

typedef struct Timer {
	float duration;
	int start_time;
	bool active;
	bool repeat;
	//bool autostart;
	void (*Activate)(struct Timer *t);
	void (*Deactivate)(struct Timer *t);
	void (*Update)(struct Timer *t);
	void (*func)(void);
} Timer;

Timer CreateTimer(void);
#endif
