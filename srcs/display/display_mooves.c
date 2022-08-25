/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:21:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:05:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moove(t_data *img)
{
	char	*mooves;

	mooves = ft_itoa(img->mooves);
	if (!mooves)
	{
		destroy(img);
		error("Error\nMalloc : Itoa > display_mooves\n");
	}
	mlx_put_image_to_window(img->mlx, img->window, img->wall, 0, 0);
	img->mooves_displayed = mlx_string_put
		(img->mlx, img->window, 16, 20, 0x00F87736, mooves);
	free(mooves);
}
