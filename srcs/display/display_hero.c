/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:32:47 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/14 08:21:45 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void print_hero_left(t_data *img)
{
	if (img->anim < 1000)
		mlx_put_image_to_window(img->mlx, img->window, img->hero_left, img->x_hero * 72, img->y_hero * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hero_left_up, img->x_hero * 72, img->y_hero * 72);
	img->anim++;
	if (img->anim > 2000)
		img->anim = 0;
}

static void print_hero_face(t_data *img)
{
	if (img->anim < 1000)
		mlx_put_image_to_window(img->mlx, img->window, img->hero_face, img->x_hero * 72, img->y_hero * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hero_face_up, img->x_hero * 72, img->y_hero * 72);
	img->anim++;
	if (img->anim > 2000)
		img->anim = 0;
}

static void print_hero_right(t_data *img)
{
	if (img->anim < 1000)
		mlx_put_image_to_window(img->mlx, img->window, img->hero_right, img->x_hero * 72, img->y_hero * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hero_right_up, img->x_hero * 72, img->y_hero * 72);
	img->anim++;
	if (img->anim > 2000)
		img->anim = 0;
}

static void print_hero_top(t_data *img)
{
	if (img->anim < 1000)
		mlx_put_image_to_window(img->mlx, img->window, img->hero_back, img->x_hero * 72, img->y_hero * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hero_back_up, img->x_hero * 72, img->y_hero * 72);
	img->anim++;
	if (img->anim > 2000)
		img->anim = 0;
}

void	print_hero(t_data *img)
{
	if (img->direction == 97)
		print_hero_left(img);
	if (img->direction == 115)
		print_hero_face(img);
	if (img->direction == 100)
		print_hero_right(img);
	if (img->direction == 119)
		print_hero_top(img);
}
