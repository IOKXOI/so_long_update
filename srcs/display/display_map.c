/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:49:06 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/19 02:03:56 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void 	init_ressources_enemies(t_data *img)
{
	img->hisoka_attackright3 = NULL;
	img->hisoka_right1 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_right1.xpm", &img->width, &img->height);
	img->hisoka_rightwalk1 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_rightwalk1.xpm", &img->width, &img->height);
	img->hisoka_rightwalk2 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_rightwalk2.xpm", &img->width, &img->height);
	img->hisoka_rightwalk3 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_rightwalk3.xpm", &img->width, &img->height);
	img->hisoka_rightwalk4 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_rightwalk4.xpm", &img->width, &img->height);
	img->hisoka_left1 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_left1.xpm", &img->width, &img->height);
	img->hisoka_leftwalk1 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_leftwalk1.xpm", &img->width, &img->height);
	img->hisoka_leftwalk2 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_leftwalk2.xpm", &img->width, &img->height);
	img->hisoka_leftwalk3 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_leftwalk3.xpm", &img->width, &img->height);
	img->hisoka_leftwalk4 = mlx_xpm_file_to_image(img->mlx, "./ressources/hisoka_leftwalk4.xpm", &img->width, &img->height);
	img->hisoka_attackright3 = mlx_xpm_file_to_image(img->mlx, "./ressources/Hisoka_attackright3.xpm", &img->width, &img->height);
	img->hisoka_attackleft3 = mlx_xpm_file_to_image(img->mlx, "./ressources/Hisoka_attackleft3.xpm", &img->width, &img->height);
	//img->ground = mlx_xpm_file_to_image(img->mlx, "./ressources/ground.xpm", &img->width, &img->height);
	// img->chicken = mlx_xpm_file_to_image(img->mlx, "./ressources/collectible.xpm", &img->width, &img->height);
	// img->portal = mlx_xpm_file_to_image(img->mlx, "./ressources/portal.xpm", &img->width, &img->height);img->hero_face = mlx_xpm_file_to_image(img->mlx, "./ressources/face.xpm", &img->width, &img->height);
	// img->hero_face_up = mlx_xpm_file_to_image(img->mlx, "./ressources/face_up.xpm", &img->width, &img->height);
	// img->hero_back = mlx_xpm_file_to_image(img->mlx, "./ressources/back.xpm", &img->width, &img->height);
	// img->hero_back_up = mlx_xpm_file_to_image(img->mlx, "./ressources/back_up.xpm", &img->width, &img->height);
	// img->hero_left = mlx_xpm_file_to_image(img->mlx, "./ressources/left.xpm", &img->width, &img->height);
	// img->hero_left_up = mlx_xpm_file_to_image(img->mlx, "./ressources/left_up.xpm", &img->width, &img->height);
	// img->hero_right = mlx_xpm_file_to_image(img->mlx, "./ressources/right.xpm", &img->width, &img->height);
	// img->hero_right_up = mlx_xpm_file_to_image(img->mlx, "./ressources/right_up.xpm", &img->width, &img->height);
	if (check_init(img))
	{
		free_map(img);
		free(img->mlx);
		free_ressources(img);
		error("Initialisation failed, check xpm ressources");
	}
}

void 	init_ressources(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "./ressources/obstacle.xpm", &img->width, &img->height);
	img->ground = mlx_xpm_file_to_image(img->mlx, "./ressources/ground.xpm", &img->width, &img->height);
	img->chicken = mlx_xpm_file_to_image(img->mlx, "./ressources/collectible.xpm", &img->width, &img->height);
	img->portal = mlx_xpm_file_to_image(img->mlx, "./ressources/portal.xpm", &img->width, &img->height);img->hero_face = mlx_xpm_file_to_image(img->mlx, "./ressources/face.xpm", &img->width, &img->height);
	img->hero_face_up = mlx_xpm_file_to_image(img->mlx, "./ressources/face_up.xpm", &img->width, &img->height);
	img->hero_back = mlx_xpm_file_to_image(img->mlx, "./ressources/back.xpm", &img->width, &img->height);
	img->hero_back_up = mlx_xpm_file_to_image(img->mlx, "./ressources/back_up.xpm", &img->width, &img->height);
	img->hero_left = mlx_xpm_file_to_image(img->mlx, "./ressources/left.xpm", &img->width, &img->height);
	img->hero_left_up = mlx_xpm_file_to_image(img->mlx, "./ressources/left_up.xpm", &img->width, &img->height);
	img->hero_right = mlx_xpm_file_to_image(img->mlx, "./ressources/right.xpm", &img->width, &img->height);
	img->hero_right_up = mlx_xpm_file_to_image(img->mlx, "./ressources/right_up.xpm", &img->width, &img->height);
	init_ressources_enemies(img);
	if (check_init(img))
	{
		free_map(img);
		free(img->mlx);
		free_ressources(img);
		error("Initialisation failed, check xpm ressources");
	}
}
//bug//
void printtab(t_data *img, char **tab, int x_max, int y_max)
{
	int x = 0;
	int y = 0;

	if (img->i < 20)
	{
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
		printf("img -> aim = %d \n", img->anim);
	}
}

//

int	display_map(t_data *img)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	// printf("==============");
  	// print_struct(img->enemies);
  	// printf("==============");  
	while(y < img->y && x < img->x)
	{
		if (img->map[y][x] == 'E')
			print_exit(img);
		if (img->map[y][x] == 'P')
			print_hero(img);
		if (img->map[y][x] == 'M')
			print_enemy(img);
		x++;
		if (x == img->x)
		{
			x = 0;
			y++;
		}
	}
	printtab(img, img->map, img->x, img->y);
	img->i++;
	return (0);
}
