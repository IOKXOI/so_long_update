/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:58:49 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:29:38 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_node(t_data *img, int x, int y)
{
	img->enemies = malloc(sizeof(t_enemies));
	if (!img->enemies)
	{
		error("Error\n malloc < add_enemy < scan_elements < check_convert\n");
		destroy(img);
	}
	img->enemies->first = img->enemies;
	img->enemies->id = img->monster;
	img->enemies->x_pos = x;
	img->enemies->y_pos = y;
	img->enemies->direction = 3;
	if (x * y > 10)
		img->enemies->fram_four = (x * y) * ANIM_LIMIT;
	else
		img->enemies->fram_four = 3 * ANIM_LIMIT;
	if (img->enemies->fram_four > (ANIM_LIMIT * 5))
		img->enemies->fram_four /= 2;
	img->enemies->fram_one = img->enemies->fram_four / 4;
	img->enemies->fram_two = img->enemies->fram_one * 2;
	img->enemies->fram_three = img->enemies->fram_one * 3;
	img->enemies->fram_four = img->enemies->fram_one * 4;
	img->enemies->i = 1;
	img->enemies->anim_up = 0;
	img->enemies->random_action = 0;
	img->enemies->direction = 3;
	img->enemies->once = 0;
	img->enemies->last = img->enemies;
	img->enemies->next = NULL;
}

t_enemies	*new_node(t_data *img, int x, int y)
{
	t_enemies	*new_enemy;

	new_enemy = malloc(sizeof(t_enemies));
	if (!new_enemy)
	{
		free_list(img);
		error("Error\n malloc < new_node < scan_elements < check_convert\n");
		destroy(img);
	}
	img->enemies->last->next = new_enemy;
	new_enemy->first = img->enemies->first;
	new_enemy->id = img->monster;
	new_enemy->x_pos = x;
	new_enemy->y_pos = y;
	if (x * y > 10)
		new_enemy->fram_four = (x * y) * ANIM_LIMIT;
	else
		new_enemy->fram_four = 3 * ANIM_LIMIT;
	if (new_enemy->fram_four > (ANIM_LIMIT * 5))
		new_enemy->fram_four /= 2;
	new_enemy->fram_one = new_enemy->fram_four / 4;
	new_enemy->fram_two = new_enemy->fram_one * 2;
	new_enemy->fram_three = new_enemy->fram_one * 3;
	new_enemy->fram_four = new_enemy->fram_one * 4;
	new_enemy->i = 1;
	new_enemy->random_action = 0;
	new_enemy->direction = 3;
	new_enemy->once = 0;
	new_enemy->next = NULL;
	return (new_enemy);
}

void	add_enemies(t_data *img, int x, int y)
{
	if (!img->enemies)
		init_node(img, x, y);
	else
		img->enemies->first->last = new_node(img, x, y);
}
