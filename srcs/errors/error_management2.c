/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:53:57 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/25 20:26:14 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_open(char *map_ber)
{
	int	fd;

	fd = open(map_ber, O_DIRECTORY);
	if (fd != -1)
		error("Error\nMain > convert_map > open");
	fd = open(map_ber, O_RDONLY);
	if (fd < 0)
		error("Error\nMain > convert_map > open");
	return (fd);
}
