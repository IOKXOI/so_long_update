/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:29:46 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 01:57:45 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove_pos(t_enemies *this_enemy, int x, int y)
{
	this_enemy->i = -1;
	this_enemy->x += x;
	this_enemy->y += y;
	this_enemy->once = 0;
}
