#include "debugging.h"

void Debug_Player(Player *p)
{
	char current_text[1000+1] = {'\0'};
	char result_text[1000+1] = {'\0'};
	snprintf(current_text, 1000, "speed: %f\n", p->speed);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "position: X:%f  Y:%f\n", p->position.x, 
								p->position.y);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "drawing_s: X:%f  Y:%f  W:%f  H:%f\n", 
		p->drawing_s.x, p->drawing_s.y, p->drawing_s.width, 
		p->drawing_s.height);

	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "hurtbox_s: X:%f  Y:%f  W:%f  H:%f\n", 
		p->hurtbox_s.x, p->hurtbox_s.y, p->hurtbox_s.width, 
		p->hurtbox_s.height);

	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "bullet_cd: %f\n", p->bullet_cd);
	strncat(result_text, current_text, 1000);

	snprintf(current_text, 1000, "special_cd: %f\n", p->special_cd);
	strncat(result_text, current_text, 1000);

	DrawText(result_text, 0, 0, 20, WHITE);
}
