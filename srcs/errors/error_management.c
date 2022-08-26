/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 00:01:54 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_map(t_data *img)
{
	int	y;

	y = 0;
	while (y < img->y)
	{
		free(img->map[y]);
		y++;
	}
	free(img->map);
}

void	free_ressources(t_data *img)
{
	if (img->wall)
		free(img->wall);
	if (img->ground)
		free(img->ground);
	if (img->hero_face)
		free(img->hero_face);
	if (img->hero_face_up)
		free(img->hero_face_up);
	if (img->hero_back)
		free(img->hero_back);
	if (img->hero_back_up)
		free(img->hero_back_up);
	if (img->hero_left)
		free(img->hero_left);
	if (img->hero_left_up)
		free(img->hero_left_up);
	if (img->hero_right)
		free(img->hero_right);
	if (img->hero_right_up)
		free(img->hero_right_up);
	if (img->chicken)
		free(img->chicken);
	if (img->portal)
		free(img->portal);
}

void	free_enemies_ressources(t_data *img)
{
	if (img->right1)
		free(img->right1);
	if (img->rightwalk1)
		free(img->rightwalk1);
	if (img->rightwalk2)
		free(img->rightwalk3);
	if (img->rightwalk4)
		free(img->rightwalk4);
	if (img->attackright3)
		free(img->attackright3);
	if (img->left1)
		free(img->left1);
	if (img->leftwalk1)
		free(img->leftwalk1);
	if (img->leftwalk2)
		free(img->leftwalk2);
	if (img->leftwalk3)
		free(img->leftwalk3);
	if (img->leftwalk4)
		free(img->leftwalk4);
	if (img->attackleft3)
		free(img->attackleft3);
}

void	free_list(t_data *img)
{
	void	*next;

	if (img->enemies)
		img->enemies = img->enemies->first;
	if (img->enemies)
	{
		while (img->enemies)
		{
			next = img->enemies->next;
			free(img->enemies);
			img->enemies = next;
		}
		free(img->enemies);
	}
}
