/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:17:17 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/26 03:43:17 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
		i++;
	if (argv[i - 3] != '.' || argv[i - 2] != 'b'
		|| argv[i - 1] != 'e' || argv[i] != 'r' || ft_strlen(argv) < 5)
	{
		write (1, "Error\nNot good map extension", 28);
		exit(EXIT_FAILURE);
	}
}

void	check_arg(int argc, char *argv)
{
	{
		if (argc < 2)
		{
			write(1, "Error\nMap is missing", 20);
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			write(1, "Error\nKeep calm ! One by one It will be alright", 47);
			exit(EXIT_FAILURE);
		}
	}
	check_extension(argv);
}
