/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:33:44 by iok               #+#    #+#             */
/*   Updated: 2022/08/26 04:21:33 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_characters(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	return (i);
}

static int	check_lenght(int map_lenght, char *s1)
{
	if (count_characters(s1) != map_lenght)
	{
		free(s1);
		write(1, "Error\nInvalid map lenght\n", 24);
		return (1);
	}
	return (0);
}

static int	count_lines(char *map_ber, t_data *img)
{
	int		fd;
	char	*s1;

	img->y = 0;
	fd = check_open(map_ber);
	s1 = get_next_line(fd);
	if (!s1)
		error("Error\n count_line > GNL");
	img->y = img->y + 1;
	img->x = count_characters(s1);
	while (s1)
	{
		free(s1);
		s1 = get_next_line(fd);
		if (s1 && *s1 != '\n')
			img->y = img->y + 1;
		if (s1 && *s1 != '\n' && check_lenght(img->x, s1))
		{
			flush_gnl(fd);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	return (img->y);
}

static void	fill_tab(char **tab, char *argv, int limit)
{
	int	fd;
	int	y;

	y = 0;
	fd = check_open(argv);
	while (y < limit)
	{
		tab[y] = get_next_line(fd);
		if (!tab[y])
		{
			while (y >= 0)
			{
				y--;
				free(tab[y]);
				close(fd);
			}
			error("Error\nMain > convert_map > fill_tab > get_next_line\n");
		}
		y++;
	}
	flush_gnl(fd);
	close(fd);
}

void	check_convert_and_scan_map(t_data *img, char *argv)
{
	count_lines(argv, img);
	img->map = malloc(sizeof(char *) * img->y);
	fill_tab(img->map, argv, img->y);
	check_walls(img);
	scan_elements(img);
	if (check_elements(img))
	{
		free_list(img);
		free_map(img);
		exit(EXIT_FAILURE);
	}
}
