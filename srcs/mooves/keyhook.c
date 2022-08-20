/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:49:07 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/20 03:30:51 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moove_left(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero - 1] != '1')
	{
		img->x_hero--;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		else if (img->map[img->y_hero][img->x_hero] == 'M')
		{
			while(img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackright3, img->x_hero * 72, img->y_hero * 72);
				img->anim++;
			}
			destroy(img);
		}
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, (img->x_hero + 1) * 72, img->y_hero * 72);
		img->map[img->y_hero][img->x_hero + 1] = '0';
		img->mooves++;
		//////////////////////////////////////////////////////////////////
		//debug
		printtab(img, img->map, img->x, img->y);
		print_struct(img->enemies);
		////
	}
}

static void	moove_right(int keycode, t_data *img)
{
	if (img->map[img->y_hero][img->x_hero + 1] != '1')
	{
		img->x_hero++;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		else if (img->map[img->y_hero][img->x_hero] == 'M')
		{
			while(img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackleft3, img->x_hero * 72, img->y_hero * 72);
				img->anim++;
			}
			destroy(img);
		}
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero][img->x_hero - 1] = '0';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, (img->x_hero - 1) * 72, img->y_hero * 72);
		img->mooves++;
		//////////////////////////////////////////////////////////////////
		//debug
		printtab(img, img->map, img->x, img->y);
		print_struct(img->enemies);
		////
	}
}

static void	moove_down(int keycode, t_data *img)
{
	if (img->map[img->y_hero + 1][img->x_hero] != '1')
	{
		img->y_hero++;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		else if (img->map[img->y_hero][img->x_hero] == 'M')
		{
			while(img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackright3, img->x_hero * 72, img->y_hero * 72);
				img->anim++;
			}
			destroy(img);
		}
		// 	hisokill();
		// else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		// 	gg_wp();
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero - 1][img->x_hero] = '0';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, img->x_hero * 72, (img->y_hero - 1) * 72);
		img->mooves++;
		//////////////////////////////////////////////////////////////////
		//debug
		printtab(img, img->map, img->x, img->y);
		print_struct(img->enemies);
		////
	}
}

static void	moove_up(int keycode, t_data *img)
{
	if (img->map[img->y_hero - 1][img->x_hero] != '1')
	{
		img->y_hero--;
		if (img->map[img->y_hero][img->x_hero] == 'C')
		{
			img->collectible--;
			if (!img->collectible)
				img->map[img->y_exit][img->x_exit] = 'E';
		}
		else if (img->map[img->y_hero][img->x_hero] == 'M')
		{
			while(img->anim < (ANIM_LIMIT * 10))
			{
				mlx_put_image_to_window(img->mlx, img->window, img->hisoka_attackright3, img->x_hero * 72, img->y_hero * 72);
				img->anim++;
			}
			destroy(img);
		}
		// 	hisokill();
		 else if (img->map[img->y_hero][img->x_hero] == 'E' && img->collectible == 0)
		 	gg_wp(img);
		img->map[img->y_hero][img->x_hero] = 'P';
		img->map[img->y_hero + 1][img->x_hero] = '0';
		mlx_put_image_to_window(img->mlx, img->window, img->ground, img->x_hero * 72, (img->y_hero + 1) * 72);
		img->mooves++;
		//////////////////////////////////////////////////////////////////
		//debug
		printtab(img, img->map, img->x, img->y);
		print_struct(img->enemies);
		////	
	}
}

int	which_key(int keycode, t_data *img)
{
	if (keycode == LEFT)
	{
		if (keycode == img->direction)
			moove_left(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == RIGHT)
	{
		if (keycode == img->direction)
			moove_right(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == DOWN)
	{
		if (keycode == img->direction)
			moove_down(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == TOP)
	{
		if (keycode == img->direction)
			moove_up(keycode, img);
		img->direction = keycode;
	}
	else if (keycode == 65307)
		destroy(img);
	return (0);
}
