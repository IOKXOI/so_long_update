/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict_moove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:00:13 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:03:17 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	look_left(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y][this_enemy->x - 1] != '1'
		&& img->map[this_enemy->y][this_enemy->x - 1] != 'M'
		&& img->map[this_enemy->y][this_enemy->x - 2] != 'M'
		&& img->map[this_enemy->y][this_enemy->x - 1] != 'E'
		&& img->map[this_enemy->y][this_enemy->x - 1] != 'C')
	{
		this_enemy->direction = 1;
		return (1);
	}
	this_enemy->random_action++;
	return (0);
}

static int	look_right(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y][this_enemy->x + 1] != '1'
		&& img->map[this_enemy->y][this_enemy->x + 1] != 'M'
		&& img->map[this_enemy->y][this_enemy->x + 2] != 'M'
		&& img->map[this_enemy->y][this_enemy->x + 1] != 'E'
		&& img->map[this_enemy->y][this_enemy->x + 1] != 'C')
	{
		this_enemy->direction = 3;
		return (1);
	}
	this_enemy->random_action++;
	return (0);
}

static int	look_down(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y + 1][this_enemy->x] != '1'
		&& img->map[this_enemy->y + 1][this_enemy->x] != 'M'
		&& img->map[this_enemy->y + 2][this_enemy->x] != 'M'
		&& img->map[this_enemy->y + 1][this_enemy->x] != 'E'
		&& img->map[this_enemy->y + 1][this_enemy->x] != 'C')
		return (1);
	this_enemy->random_action++;
	return (0);
}

static int	look_top(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y - 1][this_enemy->x] != '1'
		&& img->map[this_enemy->y - 1][this_enemy->x] != 'M'
		&& img->map[this_enemy->y - 2][this_enemy->x] != 'M'
		&& img->map[this_enemy->y - 1][this_enemy->x] != 'E'
		&& img->map[this_enemy->y - 1][this_enemy->x] != 'C')
		return (1);
	this_enemy->random_action++;
	return (0);
}

int	look_for_this_action(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->random_action == 1 || this_enemy->random_action == 6)
		if (look_left(img, this_enemy))
			return (1);
	if (this_enemy->random_action == 2 || this_enemy->random_action == 7)
		if (look_down(img, this_enemy))
			return (1);
	if (this_enemy->random_action == 3 || this_enemy->random_action == 8)
		if (look_right(img, this_enemy))
			return (1);
	if (this_enemy->random_action == 4 || this_enemy->random_action == 9)
		if (look_top(img, this_enemy))
			return (1);
	this_enemy->random_action = 0;
	return (1);
}
