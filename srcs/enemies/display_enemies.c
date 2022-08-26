/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 05:58:15 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:43:55 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hisokill(t_data *img, t_enemies *this_enemy)
{
	int	i;

	i = 0;
	while (i < (ANIM_LIMIT * 50))
	{
		if (this_enemy->direction == 3)
			mlx_put_image_to_window(img->mlx, img->window, img->attackright3,
				this_enemy->x * 72, this_enemy->y * 72);
		else
			mlx_put_image_to_window(img->mlx, img->window, img->attackleft3,
				this_enemy->x * 72, this_enemy->y * 72);
		i++;
	}
	write(1, "GAME OVER !", 11);
	destroy(img);
}

void	print_static_hisoka(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
		mlx_put_image_to_window(img->mlx, img->window, img->left1,
			this_enemy->x * 72, this_enemy->y * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->right1,
			this_enemy->x * 72, this_enemy->y * 72);
	if (this_enemy->i >= this_enemy->fram_four)
	{
		this_enemy->i = -1;
		this_enemy->random_action++;
	}
}

void	set_anim(t_data *img, t_enemies *this_enemy)
{
	this_enemy->random_action = random_number(img, this_enemy);
	while (!look_for_this_action(img, this_enemy))
	{
		this_enemy->random_action = this_enemy->random_action + 1;
		if (this_enemy->random_action > 9)
			this_enemy->random_action = random_number(img, this_enemy);
	}
}

static void	display_anim(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->random_action == 0)
		print_static_hisoka(img, this_enemy);
	else if (this_enemy->random_action == 1 || this_enemy->random_action == 6)
		moove_enemy_left(img, this_enemy);
	else if (this_enemy->random_action == 2 || this_enemy->random_action == 7)
		moove_enemy_down(img, this_enemy);
	else if (this_enemy->random_action == 3 || this_enemy->random_action == 8)
		moove_enemy_right(img, this_enemy);
	else if (this_enemy->random_action == 4 || this_enemy->random_action == 9)
		moove_enemy_top(img, this_enemy);
}

void	print_enemy(t_data *img)
{
	t_enemies	*each_enemy;

	each_enemy = img->enemies->first;
	while (each_enemy)
	{
		if (each_enemy->random_action == 5)
			each_enemy->random_action = 0;
		if (each_enemy->i > each_enemy->fram_four)
			each_enemy->i = 0;
		if (each_enemy->i <= 0)
			set_anim(img, each_enemy);
		display_anim(img, each_enemy);
		each_enemy->i++;
		each_enemy = each_enemy->next;
	}
}
