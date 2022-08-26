/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:32:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 02:09:26 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_place(t_data *img, t_enemies *enemy, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->window, img->ground,
		enemy->x * 72, enemy->y * 72);
	img->map[enemy->y][enemy->x] = '0';
	img->map[y][x] = 'M';
	enemy->once = 1;
}

int	moove_enemy_left(t_data *img, t_enemies *this_enemy)
{
	this_enemy->direction = 1;
	if (this_enemy->i < this_enemy->fram_one)
		mlx_put_image_to_window(img->mlx, img->window, img->leftwalk1,
			this_enemy->x * 72, this_enemy->y * 72);
	else if (this_enemy->i < this_enemy->fram_two)
		mlx_put_image_to_window(img->mlx, img->window, img->leftwalk2,
			this_enemy->x * 72, this_enemy->y * 72);
	else if (this_enemy->i < this_enemy->fram_three)
	{
		if (img->map[this_enemy->y][this_enemy->x - 1] == 'P')
			hisokill(img, this_enemy);
		mlx_put_image_to_window(img->mlx, img->window, img->leftwalk3,
			(this_enemy->x -1) * 72, this_enemy->y * 72);
		if (!this_enemy->once)
			change_place(img, this_enemy, this_enemy->x - 1, this_enemy->y);
	}
	else if (this_enemy->i < this_enemy->fram_four)
		mlx_put_image_to_window(img->mlx, img->window,
			img->leftwalk4, (this_enemy->x - 1) * 72, this_enemy->y * 72);
	else if (this_enemy->i >= this_enemy->fram_four)
		moove_pos(this_enemy, -1, 0);
	return (0);
}

int	moove_enemy_right(t_data *img, t_enemies *this_enemy)
{
	this_enemy->direction = 3;
	if (this_enemy->i < this_enemy->fram_one)
		mlx_put_image_to_window(img->mlx, img->window, img->rightwalk1,
			this_enemy->x * 72, this_enemy->y * 72);
	else if (this_enemy->i < this_enemy->fram_two)
		mlx_put_image_to_window(img->mlx, img->window, img->rightwalk2,
			this_enemy->x * 72, this_enemy->y * 72);
	else if (this_enemy->i < this_enemy->fram_three)
	{
		if (img->map[this_enemy->y][this_enemy->x + 1] == 'P')
			hisokill(img, this_enemy);
		mlx_put_image_to_window(img->mlx, img->window,
			img->rightwalk3, (this_enemy->x + 1) * 72, this_enemy->y * 72);
		if (!this_enemy->once)
			change_place(img, this_enemy, this_enemy->x + 1, this_enemy->y);
	}
	else if (this_enemy->i < this_enemy->fram_four)
	{	
		mlx_put_image_to_window(img->mlx, img->window,
			img->rightwalk4, (this_enemy->x + 1) * 72, this_enemy->y * 72);
	}
	else if (this_enemy->i >= this_enemy->fram_four)
		moove_pos(this_enemy, 1, 0);
	return (0);
}

int	moove_enemy_top(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y - 1][this_enemy->x] == 'P')
		hisokill(img, this_enemy);
	if (this_enemy->i < this_enemy->fram_four)
	{
		if (!this_enemy->once)
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground,
				this_enemy->x * 72, this_enemy->y * 72);
			img->map[this_enemy->y][this_enemy->x] = '0';
			img->map[this_enemy->y - 1][this_enemy->x] = 'M';
			this_enemy->once = 1;
		}
		if (this_enemy->direction == 1)
			mlx_put_image_to_window(img->mlx, img->window, img->left1,
				this_enemy->x * 72, (this_enemy->y - 1) * 72);
		else
			mlx_put_image_to_window(img->mlx, img->window, img->right1,
				this_enemy->x * 72, (this_enemy->y - 1) * 72);
	}
	else
		moove_pos(this_enemy, 0, -1);
	return (0);
}

int	moove_enemy_down(t_data *img, t_enemies *this_enemy)
{
	if (img->map[this_enemy->y + 1][this_enemy->x] == 'P')
		hisokill(img, this_enemy);
	if (this_enemy->i < this_enemy->fram_four)
	{
		if (!this_enemy->once)
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground,
				this_enemy->x * 72, this_enemy->y * 72);
			img->map[this_enemy->y][this_enemy->x] = '0';
			img->map[this_enemy->y + 1][this_enemy->x] = 'M';
			this_enemy->once = 1;
		}
		if (this_enemy->direction == 1)
			mlx_put_image_to_window(img->mlx, img->window, img->left1,
				this_enemy->x * 72, (this_enemy->y + 1) * 72);
		else
			mlx_put_image_to_window(img->mlx, img->window, img->right1,
				this_enemy->x * 72, (this_enemy->y + 1) * 72);
	}
	else
		moove_pos(this_enemy, 0, 1);
	return (0);
}
