/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:58:49 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 02:26:26 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_next(t_enemies *enemy)
{
	enemy->fram_one = enemy->fram_four / 4;
	enemy->fram_two = enemy->fram_one * 2;
	enemy->fram_three = enemy->fram_one * 3;
	enemy->fram_four = enemy->fram_one * 4;
	enemy->i = 1;
	enemy->random_action = 0;
	enemy->direction = 3;
	enemy->once = 0;
	enemy->next = NULL;
}

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
	img->enemies->x = x;
	img->enemies->y = y;
	img->enemies->direction = 3;
	if (x * y > 10)
		img->enemies->fram_four = (x * y) * ANIM_LIMIT;
	else
		img->enemies->fram_four = 3 * ANIM_LIMIT;
	if (img->enemies->fram_four > (ANIM_LIMIT * 5))
		img->enemies->fram_four /= 2;
	init_next(img->enemies);
	img->enemies->last = img->enemies;
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
	new_enemy->x = x;
	new_enemy->y = y;
	if (x * y > 10)
		new_enemy->fram_four = (x * y) * ANIM_LIMIT;
	else
		new_enemy->fram_four = 3 * ANIM_LIMIT;
	if (new_enemy->fram_four > (ANIM_LIMIT * 5))
		new_enemy->fram_four /= 2;
	init_next(new_enemy);
	return (new_enemy);
}

void	add_enemies(t_data *img, int x, int y)
{
	if (!img->enemies)
		init_node(img, x, y);
	else
		img->enemies->first->last = new_node(img, x, y);
}
