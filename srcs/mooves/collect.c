/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:54:19 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:33:04 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect(t_data *img)
{
	img->collectible--;
	if (!img->collectible)
	{
		img->map[img->y_exit][img->x_exit] = 'E';
		mlx_put_image_to_window(img->mlx, img->window,
			img->portal, img->x_exit * 72, img->y_exit * 72);
	}
}
