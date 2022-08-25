/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:27:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:39:38 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_enemy_ressources(t_data *img)
{
	mlx_destroy_image(img->mlx, img->hisoka_right1);
	mlx_destroy_image(img->mlx, img->hisoka_rightwalk1);
	mlx_destroy_image(img->mlx, img->hisoka_rightwalk2);
	mlx_destroy_image(img->mlx, img->hisoka_rightwalk3);
	mlx_destroy_image(img->mlx, img->hisoka_rightwalk4);
	mlx_destroy_image(img->mlx, img->hisoka_left1);
	mlx_destroy_image(img->mlx, img->hisoka_leftwalk1);
	mlx_destroy_image(img->mlx, img->hisoka_leftwalk2);
	mlx_destroy_image(img->mlx, img->hisoka_leftwalk3);
	mlx_destroy_image(img->mlx, img->hisoka_leftwalk4);
	mlx_destroy_image(img->mlx, img->hisoka_attackright3);
	mlx_destroy_image(img->mlx, img->hisoka_attackleft3);
}

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
	destroy_enemy_ressources(img);
}

int	destroy(t_data *img)
{
	destroy_ressources(img);
	free_map(img);
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	free_list(img);
	exit(EXIT_SUCCESS);
}

void	gg_wp(t_data *img)
{
	destroy(img);
}
