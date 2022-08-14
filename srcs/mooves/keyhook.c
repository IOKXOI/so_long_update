/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:49:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/14 15:01:56 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moove_left(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero - 1] != '1' && img->map[img->y_hero][img->x_hero - 1] != 'M')
	{
		if (img->map[img->y_hero][img->x_hero - 1] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		if (img->map[img->y_hero][img->x_hero - 1] == 'E' && img->collectible == 0)
			write(1, "GG", 2);
		if (img->map[img->y_hero][img->x_hero] != 'E')
			img->map[img->y_hero][img->x_hero] = '0';
		img->map[img->y_hero][img->x_hero - 1] = 'P';
		img->x_hero--;
	}
	if (img->map[img->y_hero][img->x_hero - 1] == 'M')
		write(1, "GAME OVER", 9);
}

static void	moove_right(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero + 1] != '1' && img->map[img->y_hero][img->x_hero + 1] != 'M')
	{
		if (img->map[img->y_hero][img->x_hero + 1] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
			{
				img->map[img->y_exit][img->x_exit] = 'E';
			}
		}
		if (img->map[img->y_hero][img->x_hero + 1] == 'E' && img->collectible == 0)
			write(1, "GG", 2);
		if (img->map[img->y_hero][img->x_hero] != 'E')
			img->map[img->y_hero][img->x_hero] = '0';
		img->map[img->y_hero][img->x_hero + 1] = 'P';
		img->x_hero++;
	}
	if (img->map[img->y_hero][img->x_hero + 1] == 'M')
		write(1, "GAME OVER", 9);
}

static void	moove_down(int keycode, t_data *img)
{
	if (img->map[img->y_hero + 1][img->x_hero] != '1' && img->map[img->y_hero + 1][img->x_hero] != 'M')
	{
		if (img->map[img->y_hero + 1][img->x_hero] == 'C')
		{
			img->collectible--;
			if (img->collectible)
			{
				img->map[img->y_exit][img->x_exit] = 'E';
			}
		}
		if (img->map[img->y_hero + 1][img->x_hero] == 'E' && img->collectible == 0)
			write(1, "GG", 2);
		if (img->map[img->y_hero][img->x_hero] != 'E')
			img->map[img->y_hero][img->x_hero] = '0';
		img->map[img->y_hero + 1][img->x_hero] = 'P';
		img->y_hero++;
	}
	if (img->map[img->y_hero + 1][img->x_hero] == 'M')
		write(1, "GAME OVER", 9);
}

static void	moove_up(int keycode, t_data *img)
{
	if (img->map[img->y_hero - 1][img->x_hero] != '1' && img->map[img->y_hero - 1][img->x_hero] != 'M')
	{
		if (img->map[img->y_hero - 1][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
			{
				img->map[img->y_exit][img->x_exit] = 'E';
			}
		}
		if (img->map[img->y_hero - 1][img->x_hero] == 'E' && img->collectible == 0)
			write(1, "GG", 2);
		if (img->map[img->y_hero][img->x_hero] != 'E')
			img->map[img->y_hero][img->x_hero] = '0';
		img->map[img->y_hero - 1][img->x_hero] = 'P';
		img->y_hero--;
	}
	if (img->map[img->y_hero - 1][img->x_hero] == 'M')
		write(1, "GAME OVER", 9);
}

int	which_key(int keycode, t_data *img)
{
	if (keycode == 97)
	{
		if (keycode == img->direction)
			moove_left(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == 100)
	{
		if (keycode == img->direction)
			moove_right(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == 115)
	{
		if (keycode == img->direction)
			moove_down(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == 119)
	{
		if (keycode == img->direction)
			moove_up(keycode, img);
		img->direction = keycode;
	}
	//else if (keycode == 65307)
	//	destroy(img);
	return (0);
}
