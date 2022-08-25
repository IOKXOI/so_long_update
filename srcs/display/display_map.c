/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:49:06 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:05:20 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_map(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	display_moove(img);
	img->map[img->y_hero][img->x_hero] = 'P';
	while (y < img->y && x < img->x)
	{
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
	print_enemy(img);
	img->i++;
	return (0);
}
