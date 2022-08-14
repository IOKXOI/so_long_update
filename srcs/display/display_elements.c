/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:33:43 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/14 14:53:22 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_exit(t_data *img)
{

	if (img->collectible == 0)
		mlx_put_image_to_window(img->mlx, img->window, img->portal, img->x_exit * 72, img->y_exit * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->ground, img->x_exit * 72, img->y_exit * 72);
}

