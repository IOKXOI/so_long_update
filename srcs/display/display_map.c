/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:49:06 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/20 01:37:16 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




//bug//


//

int	display_map(t_data *img)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	// printf("==============");
  	
  	// printf("==============");  
	while(y < img->y && x < img->x)
	{
		if (img->map[y][x] == 'E')
			print_exit(img);
		if (img->map[y][x] == 'P')
			print_hero(img);
		if (img->map[y][x] == 'M')
			print_enemy(img);
		x++;
		if (x == img->x)
		{
			x = 0;
			y++;
		}
	}
	img->i++;
	return (0);
}
