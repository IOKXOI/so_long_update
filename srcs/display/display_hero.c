/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:32:47 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 01:56:29 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_hero_left(t_data *img)
{
	if (img->anim < ANIM_FRAME)
		mlx_put_image_to_window
	(img->mlx, img->window, img->hero_left, img->x_h * 72, img->y_h * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_left_up, img->x_h * 72, img->y_h * 72);
	img->anim++;
	if (img->anim > ANIM_LIMIT)
		img->anim = 0;
}

static void	print_hero_face(t_data *img)
{
	if (img->anim < ANIM_FRAME)
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_face, img->x_h * 72, img->y_h * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_face_up, img->x_h * 72, img->y_h * 72);
	img->anim++;
	if (img->anim > ANIM_LIMIT)
		img->anim = 0;
}

static void	print_hero_right(t_data *img)
{
	if (img->anim < ANIM_FRAME)
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_right, img->x_h * 72, img->y_h * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_right_up, img->x_h * 72, img->y_h * 72);
	img->anim++;
	if (img->anim > ANIM_LIMIT)
		img->anim = 0;
}

static void	print_hero_top(t_data *img)
{
	if (img->anim < ANIM_FRAME)
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_back, img->x_h * 72, img->y_h * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window,
			img->hero_back_up, img->x_h * 72, img->y_h * 72);
	img->anim++;
	if (img->anim > ANIM_LIMIT)
		img->anim = 0;
}

void	print_hero(t_data *img)
{
	if (img->direction == LEFT)
		print_hero_left(img);
	if (img->direction == RIGHT)
		print_hero_right(img);
	if (img->direction == DOWN)
		print_hero_face(img);
	if (img->direction == TOP)
		print_hero_top(img);
}
