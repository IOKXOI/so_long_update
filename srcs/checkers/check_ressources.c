/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ressources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:50:44 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 23:51:05 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_init_enemies(t_data *img)
{
	if (!img->right1 || !img->rightwalk1
		|| !img->rightwalk2 || !img->rightwalk3
		|| !img->rightwalk4 ||!img->attackright3
		|| !img->left1 || !img->leftwalk1
		|| !img->leftwalk2 || !img->leftwalk3
		|| !img->leftwalk4 || !img->attackleft3)
		return (1);
	return (0);
}

int	check_init(t_data *img)
{
	if (!img->wall || !img->ground || !img->hero_back || !img->hero_back_up
		|| !img->hero_left || !img->hero_left_up || !img->hero_right
		|| !img->hero_right_up || !img->hero_face || !img->hero_face_up
		|| !img->portal || !img->chicken || check_init_enemies(img))
		return (1);
	return (0);
}
