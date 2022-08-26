/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:49:06 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:49:10 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_hero(t_data *img)
{
	display_moove(img);
	img->map[img->y_h][img->x_h] = 'P';
	print_hero(img);
	if (img->monster > 0)
		print_enemy(img);
	add_portal(img);
	img->i++;
	return (0);
}
