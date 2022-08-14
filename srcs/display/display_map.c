/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:49:06 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/14 14:53:12 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
	if (check_init(img))
	{
		free_map(img);
		free(img->mlx);
		free_ressources(img);
		error("Initialisation failed, check xpm ressources");
	}
}

int	display_map(t_data *img)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while(y < img->y && x < img->x)
	{
		if (img->map[y][x] == '1')
			mlx_put_image_to_window(img->mlx, img->window, img->wall, x * 72, y * 72);
		if (img->map[y][x] == '0')
			mlx_put_image_to_window(img->mlx, img->window, img->ground, x * 72, y * 72);
		if (img->map[y][x] == 'C')
			mlx_put_image_to_window(img->mlx, img->window, img->chicken, x * 72, y * 72);
		if (img->map[y][x] == 'E')
			print_exit(img);
		if (img->map[y][x] == 'P')
			print_hero(img);
		x++;
		if (x == img->x)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}
