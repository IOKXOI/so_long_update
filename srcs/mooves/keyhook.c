/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:49:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:50:19 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moove_left(t_data *img)
{
	if (img->map[img->y_h][img->x_h - 1] != '1')
	{
		img->x_h--;
		if (img->map[img->y_h][img->x_h] == 'C')
			collect(img);
		else if (img->map[img->y_h][img->x_h] == 'M')
		{
			while (img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window,
					img->attackright3, img->x_h * 72, img->y_h * 72);
				img->anim++;
			}
			write(1, "GAME OVER !", 11);
			destroy(img);
		}
		else if (img->map[img->y_h][img->x_h] == 'E' && img->collectible == 0)
			gg_wp(img);
		img->map[img->y_h][img->x_h] = 'P';
		mlx_put_image_to_window(img->mlx, img->window,
			img->ground, (img->x_h + 1) * 72, img->y_h * 72);
		img->map[img->y_h][img->x_h + 1] = '0';
		img->mooves++;
		display_moove(img);
	}
}

static void	moove_right(t_data *img)
{
	if (img->map[img->y_h][img->x_h + 1] != '1')
	{
		img->x_h++;
		if (img->map[img->y_h][img->x_h] == 'C')
			collect(img);
		else if (img->map[img->y_h][img->x_h] == 'M')
		{
			while (img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window,
					img->attackleft3, img->x_h * 72, img->y_h * 72);
				img->anim++;
			}
			write(1, "GAME OVER !", 11);
			destroy(img);
		}
		else if (img->map[img->y_h][img->x_h] == 'E' && img->collectible == 0)
			gg_wp(img);
		img->map[img->y_h][img->x_h] = 'P';
		img->map[img->y_h][img->x_h - 1] = '0';
		mlx_put_image_to_window(img->mlx, img->window,
			img->ground, (img->x_h - 1) * 72, img->y_h * 72);
		img->mooves++;
		display_moove(img);
	}
}

static void	moove_down(t_data *img)
{
	if (img->map[img->y_h + 1][img->x_h] != '1')
	{
		img->y_h++;
		if (img->map[img->y_h][img->x_h] == 'C')
			collect(img);
		else if (img->map[img->y_h][img->x_h] == 'M')
		{
			while (img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window,
					img->attackright3, img->x_h * 72, img->y_h * 72);
				img->anim++;
			}
			write(1, "GAME OVER !", 11);
			destroy(img);
		}
		else if (img->map[img->y_h][img->x_h] == 'E' && img->collectible == 0)
			gg_wp(img);
		img->map[img->y_h][img->x_h] = 'P';
		img->map[img->y_h - 1][img->x_h] = '0';
		mlx_put_image_to_window(img->mlx, img->window,
			img->ground, img->x_h * 72, (img->y_h - 1) * 72);
		img->mooves++;
		display_moove(img);
	}
}

static void	moove_up(t_data *img)
{
	if (img->map[img->y_h - 1][img->x_h] != '1')
	{
		img->y_h--;
		if (img->map[img->y_h][img->x_h] == 'C')
			collect(img);
		else if (img->map[img->y_h][img->x_h] == 'M')
		{
			while (img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window,
					img->attackright3, img->x_h * 72, img->y_h * 72);
				img->anim++;
			}
			write(1, "GAME OVER !", 11);
			destroy(img);
		}
		else if (img->map[img->y_h][img->x_h] == 'E' && img->collectible == 0)
			gg_wp(img);
		img->map[img->y_h][img->x_h] = 'P';
		img->map[img->y_h + 1][img->x_h] = '0';
		mlx_put_image_to_window(img->mlx, img->window,
			img->ground, img->x_h * 72, (img->y_h + 1) * 72);
		img->mooves++;
		display_moove(img);
	}
}

int	which_key(int keycode, t_data *img)
{
	if (keycode == LEFT && keycode == img->direction)
		moove_left(img);
	else if (keycode == RIGHT && keycode == img->direction)
		moove_right(img);
	else if (keycode == DOWN && keycode == img->direction)
		moove_down(img);
	else if (keycode == TOP && keycode == img->direction)
		moove_up(img);
	else if (keycode == 65307)
		destroy(img);
	img->direction = keycode;
	return (0);
}
