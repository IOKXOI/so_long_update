/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:39:43 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 04:31:31 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_located(t_data *img, int x, int y)
{
	img->exit = img->exit + 1;
	img->x_exit = x;
	img->y_exit = y;
}

static void	hero_located(t_data *img, int x, int y)
{
	img->hero = img->hero + 1;
	img->y_h = y;
	img->x_h = x;
}

static void	enemy_located(t_data *img, int x, int y)
{
	img->monster = img->monster + 1;
	add_enemies(img, x, y);
}

void	scan_elements(t_data *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < img->y)
	{
		while (x < img->x)
		{
			if ((char)img->map[y][x] == 'C')
				img->collectible = img->collectible + 1;
			else if ((char)img->map[y][x] == 'E')
				exit_located(img, x, y);
			else if ((char)img->map[y][x] == 'P')
				hero_located(img, x, y);
			else if ((char)img->map[y][x] == 'M')
				enemy_located(img, x, y);
			else if ((char)img->map[y][x] != '0' && (char)img->map[y][x] != '1')
				bad_element(img);
			x++;
		}
		x = 0;
		y++;
	}
}

int	check_elements(t_data *img)
{
	int	check_error;

	check_error = 0;
	if (img->hero != 1)
	{
		if (img->hero < 1)
			write(1, "Error\nYour hero is missing\n", 27);
		else
			write(1, "Error\nToo much hero on the map\n", 31);
		check_error = 1;
	}
	if (img->collectible < 1)
	{
		write(1, "Error\nCollectible is missing\n", 29);
		check_error = 1;
	}
	if (img->exit != 1)
	{
		if (img->exit < 1)
			write(1, "Error\nExit is missing\n", 22);
		if (img->exit > 1)
			write(1, "Error\nToo much exit\n", 20);
		check_error = 1;
	}
	return (check_error);
}
