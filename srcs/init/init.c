/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:35:37 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/19 08:27:08 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *img)
{
	img->map = NULL;
	img->monster = 0;
	img->exit = 0;
	img->hero = 0;
	img->anim = 0;
	img->collectible = 0;
	img->x_offset = 0;
	img->y_offset = 0;
	img->direction = 97;
	img->mooves = 0;
	img->ground = NULL;
	img->wall = NULL;
	img->chicken = NULL;
	img->portal = NULL;
	img->hero_face = NULL;
	img->hero_face_up = NULL;
	img->hero_back = NULL;
	img->hero_back_up = NULL;
	img->hero_left = NULL;
	img->hero_left_up = NULL;
	img->hero_right = NULL;
	img->hero_right_up = NULL;
	img->enemies = NULL;
}

static void	init_ressources_enemies(t_data *img)
{
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
}

void	init_ressources(t_data *img)
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
	if (check_init(img) || check_init_enemies(img))
	{
		free_map(img);
		free(img->mlx);
		free_ressources(img);
		error("Initialisation failed, check xpm ressources");
	}
}

