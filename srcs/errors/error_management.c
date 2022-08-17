/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:51 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/17 04:50:48 by sydauria         ###   ########.fr       */
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


