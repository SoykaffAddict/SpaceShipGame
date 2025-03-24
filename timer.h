#include <stdbool.h>

#ifndef SPACESHIP_TIMER
#define SPACESHIP_TIMER
typedef struct Timer {
	float duration;
	int start_time;
	bool active;
	bool repeat;
	void (*Activate)(struct Timer *t, float dt);
	void (*Deactivate)(struct Timer *t, float dt);
	void (*Update)(struct Timer *t, float dt);
	void (*func)(void);
} Timer;

extern Timer Dtimer;
#endif
