#include "so_long.h"

void print_struct(t_enemies *enemy)
{
	while (enemy)
	{
		printf("id : %d\nfirst : %p\n x_pos : %d\n y_pos : %d\n direction : %d\n anim : %d\n anim_up : %d\n  random : %d\n fram_four : %d\n", enemy->id,  enemy->first,  enemy->x_pos,  enemy->y_pos,  enemy->direction,  enemy->i,  enemy->anim_up,  enemy->random_action, enemy->fram_four);

		enemy = enemy->next;
	}
}

void printtab(t_data *img, char **tab, int x_max, int y_max)
{
	int x = 0;
	int y = 0;

		while (y<y_max)
		{
			while (x<x_max)
			{
				if ( tab[y][x] == 'M')
					printf("\033[31;1;4m|%c\033[0m", tab[y][x]);
				else
					printf("|%c", tab[y][x]);
				x++;
			}
			printf("\n");
			x = 0;
			y++;
		}
		printf("=======================\n");
		printf("juste ca ca marche pas  : %p \n", img->enemies->first);
		printf("commente icic pour drole de comportement tour de boucle : %d \n", img->anim);
}
