/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:32:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/17 12:26:13 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void 	walk_one(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction = 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
}

static void 	walk_two(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction = 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk2, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk2, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
}

static void 	walk_three(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction = 1)
	{
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk3, (this_enemy->x_pos - 1) * 72, this_enemy->y_pos * 72);
		img->map[this_enemy->y_pos][this_enemy->x_pos] = '0';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	}
	else
	{
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk3, (this_enemy->x_pos + 1) * 72, this_enemy->y_pos * 72);
		img->map[this_enemy->y_pos][this_enemy->x_pos] = '0';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	}
}

static void 	walk_four(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction = 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk4, (this_enemy->x_pos - 1) * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk4, (this_enemy->x_pos + 1) * 72, this_enemy->y_pos * 72);
}

void	walking_dead(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->anim < this_enemy->fram_one)
		walk_one(img, this_enemy);
	if (this_enemy->anim < this_enemy->fram_two)
		walk_two(img, this_enemy);
	if (this_enemy->anim < this_enemy->fram_three)
		walk_three(img, this_enemy);
	if (this_enemy->anim < this_enemy->fram_four)
		walk_four(img, this_enemy);
	if (this_enemy->anim >= this_enemy->fram_four)
	{
		this_enemy->anim = 0;
		this_enemy->anim_up = 0;
	}
	// if (this_enemy->direction == 1)
		// this_enemy->x_pos--;
	// else
		// this_enemy->x_pos++;
	this_enemy->anim++;
}

int	moove_enemy_left(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos][this_enemy->x_pos - 1] == '0' 
		|| img->map[this_enemy->y_pos][this_enemy->x_pos - 1] == 'P')
	{
		this_enemy->direction = 1;
		if(img->map[this_enemy->y_pos][this_enemy->x_pos - 1] == 'P')
			hisokill(img, this_enemy);
		else
			walking_dead(img, this_enemy);
		return (1);
	}
	return(0);
}

int	moove_enemy_right(t_data *img, t_enemies *this_enemy)
{
	printf("x %d y %d\n", this_enemy->x_pos + 1, this_enemy->y_pos);
	if(img->map[this_enemy->y_pos][this_enemy->x_pos + 1] == '0' 
		|| img->map[this_enemy->y_pos][this_enemy->x_pos + 1] == 'P')
	{
		this_enemy->direction = 3;
		if(img->map[this_enemy->y_pos][this_enemy->x_pos + 1] == 'P')
			hisokill(img, this_enemy);
		else{
			printf("bonjour\n");
			walking_dead(img, this_enemy);
		}
		return (1);
	}
	return(0);
}

int	moove_enemy_top(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos - 1][this_enemy->x_pos] == '0' 
		|| img->map[this_enemy->y_pos - 1][this_enemy->x_pos] == 'P')
	{
		if(img->map[this_enemy->y_pos][this_enemy->x_pos - 1] == 'P')
			hisokill(img, this_enemy);
		else
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
			this_enemy->y_pos--;
			print_static_hisoka(img, this_enemy);
			return (1);
		}
		return (0);
	}
}

int	moove_enemy_down(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos + 1][this_enemy->x_pos] == '0' 
		|| img->map[this_enemy->y_pos + 1][this_enemy->x_pos] == 'P')
	{
		printf("bonjour\n");
		if(img->map[this_enemy->y_pos][this_enemy->x_pos + 1] == 'P')
			hisokill(img, this_enemy);
		else
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
			this_enemy->y_pos++;
			print_static_hisoka(img, this_enemy);
			return (1);
		}
		return (0);
	}
}
