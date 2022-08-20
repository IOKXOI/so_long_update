/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 05:58:15 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/20 05:41:23 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		hisokill(t_data *img, t_enemies *this_enemy)
{
	int	i;

	i = 0;
	while(i < (ANIM_LIMIT * 50))
	{
		if (this_enemy->direction == 3)
			mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackright3, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		else
			mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackleft3, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
		i++;
	}
	destroy(img);
}

void	print_static_hisoka(t_data *img, t_enemies *this_enemy)
{
	if (this_enemy->direction == 1)
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_left1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hisoka_right1, this_enemy->x_pos * 72, this_enemy->y_pos * 72);
	if (this_enemy->i >= this_enemy->fram_four)
		this_enemy->i = -1;
}

int look_for_this_action(t_data *img, t_enemies *this_enemy)
{
//	if (this_enemy->random_action == 2 || this_enemy->random_action == 4)
//		this_enemy->random_action++;
	if (this_enemy->random_action == 1 || this_enemy->random_action == 5)
	{
		if (img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != '1' 
			&& img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != 'M' 
			&& img->map[this_enemy->y_pos][this_enemy->x_pos - 2] != 'M' 
			&& img->map[this_enemy->y_pos][this_enemy->x_pos - 1] != 'C')
			{
				this_enemy->direction = 1;
				return(1);
			}
		printf("echec left enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
		return (0);
	}
	if (this_enemy->random_action == 3 || this_enemy->random_action == 8)
	{
		if (img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != '1' 
			&& img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != 'M' 
			&& img->map[this_enemy->y_pos][this_enemy->x_pos + 2] != 'M'
			&& img->map[this_enemy->y_pos][this_enemy->x_pos + 1] != 'C')
			{
				this_enemy->direction = 3;
				return(1);
			}
		printf("echec right enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
		return (0);
	}
	if (this_enemy->random_action == 2 || this_enemy->random_action == 7)
	{
		if (img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != '1' 
			&& img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != 'M' 
			&& img->map[this_enemy->y_pos + 2][this_enemy->x_pos] != 'M' 
			&& img->map[this_enemy->y_pos + 1][this_enemy->x_pos] != 'C')
				return (1);
		printf("echec down enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
		return (0);
	}
	if (this_enemy->random_action == 4 || this_enemy->random_action == 9)
	{
		if (img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != '1' 
			&& img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != 'M' 
			&& img->map[this_enemy->y_pos - 2][this_enemy->x_pos] != 'M' 
			&& img->map[this_enemy->y_pos - 1][this_enemy->x_pos] != 'C')
				return (1);
		printf("echec top enemy id = %d pos x = %d pos y = %d\n ", this_enemy->id, this_enemy->x_pos, this_enemy->y_pos );
		return (0);
	}
	if (this_enemy->random_action == 5)
	{
		this_enemy->random_action == 0;
		return (1);
	}
	if (this_enemy->random_action == 0)
	{
		printf("RRRR\n");
		return (1);
	}
	return (0);
}

void set_anim(t_data *img, t_enemies *this_enemy)
{
	char *random;

	random = malloc(10);
	if (!random)
		this_enemy->random_action = 0;
	else
		this_enemy->random_action = (int)&random % 5;
	printf("%d\n", random );
	while (!look_for_this_action(img, this_enemy))
	{
		this_enemy->random_action++;
		if (this_enemy->random_action > 9)
			this_enemy->random_action = (this_enemy->random_action * img->x_hero) % 10;
	}
	free(random);
	//this_enemy->anim_up = 1;
}

void display_anim(t_data *img, t_enemies *this_enemy)
{
	if(this_enemy->random_action == 0)
		print_static_hisoka(img, this_enemy);
	else if(this_enemy->random_action == 1 || this_enemy->random_action == 6)
		moove_enemy_left(img, this_enemy);
	else if(this_enemy->random_action == 2 || this_enemy->random_action == 7)
		moove_enemy_down(img, this_enemy);
	else if(this_enemy->random_action == 3 || this_enemy->random_action == 8)
		moove_enemy_right(img, this_enemy);
	else if(this_enemy->random_action == 4 || this_enemy->random_action == 9)
		moove_enemy_top(img, this_enemy);
	else if(this_enemy->random_action == 5)
		print_static_hisoka(img, this_enemy);
}

void print_enemy(t_data *img)
{
	t_enemies	*each_enemy;
	
	each_enemy = img->enemies->first;
	
	while(each_enemy)
	{
		///debug
		if (each_enemy->random_action == 5)
			each_enemy->random_action = 0;
		///////////
		if (each_enemy->i <= 0)
			set_anim(img, each_enemy);
		display_anim(img, each_enemy);
		each_enemy->i++;
		each_enemy = each_enemy->next;
	}
}
