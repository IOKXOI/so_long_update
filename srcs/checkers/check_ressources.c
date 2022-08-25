/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ressources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:50:44 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/24 20:24:19 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_init_enemies(t_data *img)
{
	if (!img->hisoka_right1 || !img->hisoka_rightwalk1
		|| !img->hisoka_rightwalk2 || !img->hisoka_rightwalk3
		|| !img->hisoka_rightwalk4 ||!img->hisoka_attackright3
		|| !img->hisoka_left1 || !img->hisoka_leftwalk1
		|| !img->hisoka_leftwalk2 || !img->hisoka_leftwalk3
		|| !img->hisoka_leftwalk4 || !img->hisoka_attackleft3)
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
