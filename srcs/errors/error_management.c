/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:29:23 by sydauria         ###   ########.fr       */
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
	if (img->hisoka_right1)
		free(img->hisoka_right1);
	if (img->hisoka_rightwalk1)
		free(img->hisoka_rightwalk1);
	if (img->hisoka_rightwalk2)
		free(img->hisoka_rightwalk3);
	if (img->hisoka_rightwalk4)
		free(img->hisoka_rightwalk4);
	if (img->hisoka_attackright3)
		free(img->hisoka_attackright3);
	if (img->hisoka_left1)
		free(img->hisoka_left1);
	if (img->hisoka_leftwalk1)
		free(img->hisoka_leftwalk1);
	if (img->hisoka_leftwalk2)
		free(img->hisoka_leftwalk2);
	if (img->hisoka_leftwalk3)
		free(img->hisoka_leftwalk3);
	if (img->hisoka_leftwalk4)
		free(img->hisoka_leftwalk4);
	if (img->hisoka_attackleft3)
		free(img->hisoka_attackleft3);
}

void	free_list(t_data *img)
{
	void	*next;

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
