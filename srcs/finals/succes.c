/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:27:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/17 10:40:21 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_ressources(t_data *img)
{
	mlx_destroy_image(img->mlx, img->wall);
	mlx_destroy_image(img->mlx, img->ground);
	mlx_destroy_image(img->mlx, img->hero_face);
	mlx_destroy_image(img->mlx, img->hero_face_up);
	mlx_destroy_image(img->mlx, img->hero_back);
	mlx_destroy_image(img->mlx, img->hero_back_up);
	mlx_destroy_image(img->mlx, img->hero_left);
	mlx_destroy_image(img->mlx, img->hero_left_up);
	mlx_destroy_image(img->mlx, img->hero_right);
	mlx_destroy_image(img->mlx, img->hero_right_up);
	mlx_destroy_image(img->mlx, img->chicken);
	mlx_destroy_image(img->mlx, img->portal);
}

void	destroy(t_data *img)
{
	destroy_ressources(img);
	free_map(img);
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

void	gg_wp(t_data *img)
{
	t_final	success;
	int	random;

	//random = img->mooves % 10;
	random = 0;
	destroy(img);/*
	success.mlx = mlx_init();
	if (random == 0)
	{
		success.width = 1200;
		success.height = 680;
		success.win = mlx_new_window(success.mlx, 1920, 1080, "Hello world!");
		
		success.image = mlx_xpm_file_to_image(success.mlx, "./ressources/success_alphawann.xpm", success.width, success.height);
		printf("%p\n", success.image);
		mlx_put_image_to_window(success.mlx, success.win, success.image, 0, 0);
	}
	mlx_loop(success.mlx);
	exit(EXIT_SUCCESS);*/
}
