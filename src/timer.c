#include "timer.h"


static void TimerUpdate(Timer *t);
static void TimerDeactivate(Timer *t);
static void TimerActivate(Timer *t);

static void TimerActivate(Timer *t)
{
	t->active = true;
	t->start_time = GetTime();
}

static void TimerDeactivate(Timer *t)
{
	t->active = false;
	t->start_time = 0;

	if (t->repeat)
		t->Activate(t);
}

static void TimerUpdate(Timer *t)
{
	if (t->active)
		if (GetTime() - t->start_time >= t->duration) {
			if (t->func && t->start_time)
				t->func();
			t->Deactivate(t);
		}
}

Timer CreateTimer(void)
{
	Timer DTimer = {
		.start_time = 0,
		.active = false,
		.Activate = TimerActivate,
		.Deactivate = TimerDeactivate,
		.Update = TimerUpdate,
	};

	return DTimer;
}
