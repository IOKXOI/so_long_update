/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 05:58:15 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/17 12:33:57 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		hisokill(t_data *img, t_enemies *this_enemy)
{
	while(img->anim < (ANIM_LIMIT * 10))
	{
		if (this_enemy->direction == 3)
			mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackright3, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		else
			mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackleft3, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		img->anim++;
	}
	destroy(img);
}

static void	anim_enemy(t_data *img, t_enemies *this_enemy)
{
	if (!this_enemy->anim_up)
	{
		this_enemy->random += (this_enemy->x_pos * this_enemy->y_pos) % 5; 
		this_enemy->anim_up = 1;
	}
	if (this_enemy->random == 1 && !moove_enemy_left(img, this_enemy))
		this_enemy->random++;
	if (this_enemy->random == 2 && !moove_enemy_down(img, this_enemy))
		this_enemy->random++;
	if (this_enemy->random == 3 && !moove_enemy_right(img, this_enemy))
		this_enemy->random++;
	if (this_enemy->random == 4 && !moove_enemy_top(img, this_enemy))
		this_enemy->random++;
	else
		print_static_hisoka(img, this_enemy);
//			hisok_attack(img);
}

void	print_static_hisoka(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_left1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_right1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
}

void print_enemy(t_data *img)
{
	t_enemies	*each_enemy;
	
	each_enemy = img->enemies->first;
	
	while(each_enemy)
	{
		anim_enemy(img, each_enemy);
		//mlx_put_image_to_window(img->mlx, img->window, img->hisoka_right1, each_enemy->x_pos * 72, each_enemy->y_pos * 72);
		each_enemy = each_enemy->next;
	}
	// if (img->anim < ANIM_FRAME)
		// mlx_put_image_to_window(img->mlx, img->window, img->hero_left, img->x_hero * 72, img->y_hero * 72);
	// else
		// mlx_put_image_to_window(img->mlx, img->window, img->hero_left_up, img->x_hero * 72, img->y_hero * 72);
	// img->anim++;
	// if (img->anim > ANIM_LIMIT)
		// img->anim = 0;
}
