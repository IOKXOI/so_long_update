/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:33:44 by iok               #+#    #+#             */
/*   Updated: 2022/08/14 11:05:43 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Get next line to know y lines, then malloc * y, and files. gh*/

int count_characters(char *s1)
{
    int i;
    
    i = 0;
    while(s1[i] && s1[i] != '\n')
        i++;
    return (i);
}

int check_lenght(int map_lenght, char *s1)
{
    if (count_characters(s1) != map_lenght)
    {
        free(s1);
        write(1, "Invalid map lenght", 18);
        return (1);
    }
    return (0);
}

static int count_lines(char *map_ber, t_data *img)
{
    int     fd;
    char    *s1;

    img->y = 0;
    fd = open(map_ber, O_RDONLY);
    if (fd < 0)
        error("Main > convert_map > count_lines > open");
    s1 = get_next_line(fd);
    if (!s1)
        error("Main > convert_map > count_lines > get_next_line");
    img->x = count_characters(s1);
    while (s1)
    {
        free(s1);
        s1 = get_next_line(fd);
        if (!s1)
            return (0);
        if (*s1 != '\n' && check_lenght(img->x, s1))
            return(0);
        img->y = img->y + 1;
    }
    close(fd);
    return (img->y);
}

static void fill_tab(char **tab, char *argv, int limit)
{
    int     fd;
    int     y;

    y = 0;
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        return;
    while (y < limit)
    {
        tab[y] = get_next_line(fd);
        y++;
    }
    close(fd);
}

char **check_convert_and_scan_map(t_data *img, char *argv)
{
  //  char    *result;
    //int     check_w;
    int     scan;

    count_lines(argv, img);
    img->map = malloc(sizeof(char *) * img->y);
    fill_tab(img->map, argv, img->y);
    check_walls(img);
   
    scan = scan_elements(img);
    if (scan)
    {
        write(1, "Error\nSome bad element is on the map : ", 39);
        write(1, &scan, 1);
        free_map(img);
        exit (EXIT_FAILURE);
    }
    check_elements(img);
    return (NULL);//tab);
}

