/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:32:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/19 01:52:50 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void 	walk_one(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
}

static void 	walk_two(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
	{
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk2, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		if(img->map[this_enemy->y_pos][this_enemy->x_pos - 1] == 'P')
			hisokill(img, this_enemy);
	}
	else
	{
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk2, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		if(img->map[this_enemy->y_pos][this_enemy->x_pos + 1] == 'P')
			hisokill(img, this_enemy);
	}
}

static void 	walk_three(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
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
	if (this_enemy->direction == 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_leftwalk4, (this_enemy->x_pos - 1) * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_rightwalk4, (this_enemy->x_pos + 1) * 72, this_enemy->y_pos * 72);
}

void	walking_dead(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->anim < this_enemy->fram_one)
		walk_one(img, this_enemy);
	else if (this_enemy->anim < this_enemy->fram_two)
		walk_two(img, this_enemy);
	else if (this_enemy->anim < this_enemy->fram_three)
		walk_three(img, this_enemy);
	else if (this_enemy->anim < this_enemy->fram_four)
		walk_four(img, this_enemy);
	else
	{
		if (this_enemy->direction == 1)
		{
			this_enemy->x_pos--;
			img->map[this_enemy->y_pos][this_enemy->x_pos] == 'M';
		} 
		if (this_enemy->direction == 3)
		{
			this_enemy->x_pos++;
			img->map[this_enemy->y_pos][this_enemy->x_pos] == 'M';
		}
		this_enemy->anim = 0;
		this_enemy->anim_up = 0;
		printf("fin d'anim\n");
	}
	this_enemy->anim++;
}

int	moove_enemy_left(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != '1' 
		|| img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != 'M'
		|| img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != 'C'
		|| img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != 'E')
	{
		this_enemy->direction = 1;
		walking_dead(img, this_enemy);
		return (1);
	}
	printf("echec left, enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
	return(0);
}

int	moove_enemy_right(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != '1' 
		|| img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != 'M'
		|| img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != 'C'
		|| img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != 'E')
	{
		this_enemy->direction = 3;
		walking_dead(img, this_enemy);
		return (1);
	}
	printf("echec right enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
	return(0);
}

int	moove_enemy_top(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != '1' 
		|| img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != 'M'
		|| img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != 'C'
		|| img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != 'E')
	{
		if(img->map[this_enemy->y_pos - 1][this_enemy->x_pos] == 'P')
			hisokill(img, this_enemy);
		else
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
			img->map[this_enemy->y_pos][this_enemy->y_pos] = '0';
			this_enemy->y_pos--;
			img->map[this_enemy->y_pos][this_enemy->y_pos] = 'M';
			print_static_hisoka(img, this_enemy);
			this_enemy->anim_up = 0;
			return (1);
		}
	}
	printf("echec top enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
	return (0);
}

int	moove_enemy_down(t_data *img, t_enemies *this_enemy)
{
	if(img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != '1' 
		|| img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != 'M'
		|| img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != 'C'
		|| img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != 'E')
	{
		if(img->map[this_enemy->y_pos + 1][this_enemy->x_pos] == 'P')
			hisokill(img, this_enemy);
		else
		{
			mlx_put_image_to_window(img->mlx, img->window, img->ground, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
			img->map[this_enemy->y_pos][this_enemy->y_pos] = '0';
			this_enemy->y_pos++;
			img->map[this_enemy->y_pos][this_enemy->y_pos] = 'M';
			print_static_hisoka(img, this_enemy);
			this_enemy->anim_up = 0;
			return (1);
		}
		
	}
	printf("echec down enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
	return (0);
}
