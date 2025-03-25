#include "timer.h"
#include "raylib.h"

static void ActivateF(Timer *self, float dt)
{
	self->active = true;
	self->start_time = dt;
}

static void DeactivateF(Timer *self, float dt)
{
	self->active = false;
	self->start_time = 0;

	if (self->repeat)
		self->Activate(self, dt);
}

static void UpdateF(Timer *self, float dt)
{
	if (self->active)
		if (GetTime() - self->start_time >= self->duration) {
			if (self->func && self->start_time)
				self->func();
			self->Deactivate(self, dt);
		}
}

Timer TimerCreate(void)
{
	Timer Dtimer = {
		.Activate = ActivateF,
		.Deactivate = DeactivateF,
		.Update = UpdateF,
		.start_time = 0,
		.active = false,
	};

	return Dtimer;
}
