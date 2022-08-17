/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:49:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/17 02:57:59 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moove_left(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero - 1] != '1')
	{
		img->x_hero--;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		// else if (img->map[img->y_hero][img->x_hero] == 'M')
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero][img->x_hero + 1] = '0';
		img->mooves++;
	}
}

static void	moove_right(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero + 1] != '1')
	{
		img->x_hero++;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		// else if (img->map[img->y_hero][img->x_hero] == 'M')
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero][img->x_hero - 1] = '0';
		img->mooves++;
	}
}

static void	moove_down(int keycode, t_data *img)
{
	if (img->map[img->y_hero + 1][img->x_hero] != '1')
	{
		img->y_hero++;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		// else if (img->map[img->y_hero][img->x_hero] == 'M')
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero - 1][img->x_hero] = '0';
		img->mooves++;
	}
}

static void	moove_up(int keycode, t_data *img)
{
	if (img->map[img->y_hero - 1][img->x_hero] != '1')
	{
		img->y_hero--;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		// else if (img->map[img->y_hero][img->x_hero] == 'M')
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero + 1][img->x_hero] = '0';
		img->mooves++;
	}
}

int	which_key(int keycode, t_data *img)
{
	if (keycode == LEFT)
	{
		if (keycode == img->direction)
			moove_left(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == RIGHT)
	{
		if (keycode == img->direction)
			moove_right(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == DOWN)
	{
		if (keycode == img->direction)
			moove_down(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == TOP)
	{
		if (keycode == img->direction)
			moove_up(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == 65307)
		destroy(img);
	return (0);
}
