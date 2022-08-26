/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:27:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 06:52:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_enemy_ressources(t_data *img)
{
	if (img->right1)
		mlx_destroy_image(img->mlx, img->right1);
	if (img->rightwalk1)
		mlx_destroy_image(img->mlx, img->rightwalk1);
	if (img->rightwalk2)
		mlx_destroy_image(img->mlx, img->rightwalk2);
	if (img->rightwalk3)
		mlx_destroy_image(img->mlx, img->rightwalk3);
	if (img->rightwalk4)
		mlx_destroy_image(img->mlx, img->rightwalk4);
	if (img->left1)
		mlx_destroy_image(img->mlx, img->left1);
	if (img->leftwalk1)
		mlx_destroy_image(img->mlx, img->leftwalk1);
	if (img->leftwalk2)
		mlx_destroy_image(img->mlx, img->leftwalk2);
	if (img->leftwalk3)
		mlx_destroy_image(img->mlx, img->leftwalk3);
	if (img->leftwalk4)
		mlx_destroy_image(img->mlx, img->leftwalk4);
	if (img->attackright3)
		mlx_destroy_image(img->mlx, img->attackright3);
	if (img->attackleft3)
		mlx_destroy_image(img->mlx, img->attackleft3);
}

void	destroy_ressources(t_data *img)
{
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->ground)
		mlx_destroy_image(img->mlx, img->ground);
	if (img->hero_face)
		mlx_destroy_image(img->mlx, img->hero_face);
	if (img->hero_face_up)
		mlx_destroy_image(img->mlx, img->hero_face_up);
	if (img->hero_back)
		mlx_destroy_image(img->mlx, img->hero_back);
	if (img->hero_back_up)
		mlx_destroy_image(img->mlx, img->hero_back_up);
	if (img->hero_left)
		mlx_destroy_image(img->mlx, img->hero_left);
	if (img->hero_left_up)
		mlx_destroy_image(img->mlx, img->hero_left_up);
	if (img->hero_right)
		mlx_destroy_image(img->mlx, img->hero_right);
	if (img->hero_right_up)
		mlx_destroy_image(img->mlx, img->hero_right_up);
	if (img->chicken)
		mlx_destroy_image(img->mlx, img->chicken);
	if (img->portal)
		mlx_destroy_image(img->mlx, img->portal);
	destroy_enemy_ressources(img);
}

int	destroy(t_data *img)
{
	destroy_ressources(img);
	free_map(img);
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	free_list(img);
	exit(EXIT_SUCCESS);
}

int	destroy_failure(t_data *img)
{
	destroy_ressources(img);
	free_map(img);
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	free_list(img);
	exit(EXIT_FAILURE);
}

void	gg_wp(t_data *img)
{
	write(1, "GG WP !", 7);
	destroy(img);
}
