/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:33:43 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:46:57 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_stationary(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < img->y && x < img->x)
	{
		if (img->map[y][x] == '1')
			mlx_put_image_to_window
				(img->mlx, img->window, img->wall, x * 72, y * 72);
		if (img->map[y][x] == 'C')
			mlx_put_image_to_window
				(img->mlx, img->window, img->chicken, x * 72, y * 72);
		if (img->map[y][x] == '0' || img->map[y][x] == 'E')
			mlx_put_image_to_window
				(img->mlx, img->window, img->ground, x * 72, y * 72);
		x++;
		if (x == img->x)
		{
			x = 0;
			y++;
		}
	}
}

void	display_anim(t_data *img)
{
	if (img->collectible == 0)
		mlx_put_image_to_window
	(img->mlx, img->window, img->portal, img->x_exit * 72, img->y_exit * 72);
	else
		mlx_put_image_to_window
	(img->mlx, img->window, img->ground, img->x_exit * 72, img->y_exit * 72);
}

void	add_portal(t_data *img)
{
	img->map[img->y_exit][img->x_exit] = 'E';
	if (!img->collectible)
		mlx_put_image_to_window(img->mlx, img->window,
			img->portal, img->x_exit * 72, img->y_exit * 72);
}
