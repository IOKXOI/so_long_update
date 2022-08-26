/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:53:57 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 04:31:09 by sydauria         ###   ########.fr       */
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

void	flush_gnl(int fd)
{
	char	*to_free;

	to_free = get_next_line(fd);
	while (to_free)
	{
		free(to_free);
		to_free = get_next_line(fd);
	}
}

void	bad_element(t_data *img)
{
	free_map(img);
	free_list(img);
	error("Error\nFew invalid character on the map !");
}
