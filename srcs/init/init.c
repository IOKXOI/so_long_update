/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:35:37 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:19:13 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct_enemy(t_data *img)
{
	img->right1 = NULL;
	img->rightwalk1 = NULL;
	img->rightwalk2 = NULL;
	img->rightwalk3 = NULL;
	img->rightwalk4 = NULL;
	img->left1 = NULL;
	img->leftwalk1 = NULL;
	img->leftwalk2 = NULL;
	img->leftwalk3 = NULL;
	img->leftwalk4 = NULL;
	img->attackright3 = NULL;
	img->attackleft3 = NULL;
}

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
	init_struct_enemy(img);
}

static void	init_ressources_enemies(t_data *img)
{
	img->right1 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/right1.xpm", &img->width, &img->height);
	img->rightwalk1 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/rightwalk1.xpm", &img->width, &img->height);
	img->rightwalk2 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/rightwalk2.xpm", &img->width, &img->height);
	img->rightwalk3 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/rightwalk3.xpm", &img->width, &img->height);
	img->rightwalk4 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/rightwalk4.xpm", &img->width, &img->height);
	img->left1 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/left1.xpm", &img->width, &img->height);
	img->leftwalk1 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/leftwalk1.xpm", &img->width, &img->height);
	img->leftwalk2 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/leftwalk2.xpm", &img->width, &img->height);
	img->leftwalk3 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/leftwalk3.xpm", &img->width, &img->height);
	img->leftwalk4 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/leftwalk4.xpm", &img->width, &img->height);
	img->attackright3 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/attackright3.xpm", &img->width, &img->height);
	img->attackleft3 = mlx_xpm_file_to_image
		(img->mlx, "./ressources/attackleft3.xpm", &img->width, &img->height);
}

static void	init_ressources(t_data *img)
{
	img->wall = mlx_xpm_file_to_image
		(img->mlx, "./ressources/obstacle.xpm", &img->width, &img->height);
	img->ground = mlx_xpm_file_to_image
		(img->mlx, "./ressources/ground.xpm", &img->width, &img->height);
	img->hero_face = mlx_xpm_file_to_image
		(img->mlx, "./ressources/face.xpm", &img->width, &img->height);
	img->hero_face_up = mlx_xpm_file_to_image
		(img->mlx, "./ressources/face_up.xpm", &img->width, &img->height);
	img->hero_back = mlx_xpm_file_to_image
		(img->mlx, "./ressources/back.xpm", &img->width, &img->height);
	img->hero_back_up = mlx_xpm_file_to_image
		(img->mlx, "./ressources/back_up.xpm", &img->width, &img->height);
	img->hero_left = mlx_xpm_file_to_image
		(img->mlx, "./ressources/left.xpm", &img->width, &img->height);
	img->hero_left_up = mlx_xpm_file_to_image
		(img->mlx, "./ressources/left_up.xpm", &img->width, &img->height);
	img->hero_right = mlx_xpm_file_to_image
		(img->mlx, "./ressources/right.xpm", &img->width, &img->height);
	img->hero_right_up = mlx_xpm_file_to_image
		(img->mlx, "./ressources/right_up.xpm", &img->width, &img->height);
	img->portal = mlx_xpm_file_to_image
		(img->mlx, "./ressources/portal.xpm", &img->width, &img->height);
	img->chicken = mlx_xpm_file_to_image
		(img->mlx, "./ressources/collectible.xpm", &img->width, &img->height);
	init_ressources_enemies(img);
}

void	init_ressources_and_check(t_data *img)
{
	init_ressources(img);
	if (check_init(img))
	{
		destroy_ressources(img);
		free_map(img);
		mlx_destroy_window(img->mlx, img->window);
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		free_list(img);
		error("Error\nInitialisation failed, check xpm ressources");
	}
}
