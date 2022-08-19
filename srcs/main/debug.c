#include "so_long.h"

void print_struct(t_enemies *enemy)
{
	while (enemy)
	{
		//printf("id : %d\nfirst : %p\n x_pos : %d\n y_pos : %d\n direction : %d\n anim : %d\n anim_up : %d\n  random : %d\n fram_four : %d\n", enemy->id,  enemy->first,  enemy->x_pos,  enemy->y_pos,  enemy->direction,  enemy->anim,  enemy->anim_up,  enemy->random, enemy->fram_four);

		enemy = enemy->next;
	}
}
