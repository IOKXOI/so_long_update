/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:17:17 by sydauria          #+#    #+#             */
/*   Updated: 2022/08/15 10:54:12 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void  check_extension(char *argv)
{
  int i;

  i = 0;
  while (argv[i + 1])
  {
    i++;
  }
  if (argv[i - 3] != '.' || argv[i - 2] != 'b' || argv[i - 1] != 'e' || argv[i] != 'r')
  {
    write (1, "Not good map format", 19);
    exit(EXIT_FAILURE);
  }
}

void	check_arg(int argc, char *argv)
{
  if (argc != 2)
  {
    if (argc < 2)
    {
      write(1, "Map is missing", 14);
      exit(EXIT_FAILURE);
    }
    if (argc > 2)
    {
      write(1, "Keep calm ! Only one map at the same time. It will be alright", 61);
      exit(EXIT_FAILURE);
    }
  }
  check_extension(argv);
}
