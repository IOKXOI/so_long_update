/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 05:18:13 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:06:23 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "so_long.h"

static int	is_possible_card_left(t_data *img, int x, int y)
{
	if (img->map[y][x] == '1' ||
		img->map[y][x] == 'M' || img->map[y][x] == 'C')
		return (0);
	if (img->map[y][x] == 'E' && !img->collectible)
		return (0);
	if (img->map[y][x] == 'P')
		gg_wp(img);
	else
		return (1);
}

static int	is_possible_card_right(t_data *img, int x, int y)
{
	if (img->map[y][x] == '1' ||
		img->map[y][x] == 'M' || img->map[y][x] == 'C')
		return (0);
	if (img->map[y][x] == 'E' && !img->collectible)
		return (0);
	if (img->map[y][x] == 'P')
		gg_wp(img);
	else
		return (1);
}

void	print_card_left(t_data *img, int x, int y)
{
	if (img->i < ANIM_FRAME)
	{
		mlx_put_image_to_window
			(img->mlx, img->window, img->card_left1, x * 72, y * 72);
	}
	if (img->i < ANIM_FRAME)
	{
		mlx_put_image_to_window
			(img->mlx, img->window, img->card_left2, x * 72, y * 72);
		if (img->i + 1 == ANIM_FRAME)
		{
			img->map[y][x] = '0';
			mlx_put_image_to_window
				(img->mlx, img->window, img->ground, x * 72, y * 72);
			if (is_possible_card_left(img, x - 1, y))
				img->map[y][x - 1] = '<';
		}
	}
}

void	print_card_right(t_data *img, int x, int y)
{
	if (img->i < ANIM_FRAME)
	{
		mlx_put_image_to_window
			(img->mlx, img->window, img->card_right1, x * 72, y * 72);
	}
	if (img->i < ANIM_FRAME)
	{
		mlx_put_image_to_window
			(img->mlx, img->window, img->card_right2, x * 72, y * 72);
		if (img->i + 1 == ANIM_FRAME)
		{
			img->map[y][x] = '0';
			mlx_put_image_to_window
				(img->mlx, img->window, img->ground, x * 72, y * 72);
			if (is_possible_card_right(img, x + 1, y))
				img->map[y][x + 1] = '>';
		}
	}
}
*/
