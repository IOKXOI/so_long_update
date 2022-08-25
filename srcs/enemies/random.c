/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:08:43 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:38:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	random_number(t_data *img, t_enemies *this_enemy)
{
	size_t					random;
	unsigned int			random_ret;
	char					*rdm;

	random_ret = 0;
	rdm = malloc(this_enemy->x_pos);
	if (!rdm)
		return (this_enemy->x_pos % 10);
	random = ((size_t)(&rdm));
	if (this_enemy->random_action)
		random += (this_enemy->random_action
				+ (this_enemy->x_pos * this_enemy->y_pos) + img->x_hero);
	else
		random += (1 + this_enemy->x_pos + this_enemy->y_pos);
//	if (random < 0)
//		random *= -1;
	while (random > 9)
	{
		random_ret = random_ret + (random % 10);
		random = random / 10;
	}
	while (random_ret > 9)
		random_ret = (random_ret / 10) + (random_ret % 10);
	free(rdm);
	return ((int)random_ret);
}
