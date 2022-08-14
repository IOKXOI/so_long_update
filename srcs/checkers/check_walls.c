/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:05:43 by iok               #+#    #+#             */
/*   Updated: 2022/08/14 05:24:40 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int scan_top_wall(char **map, int max_x)
{
    int x;

    x = 0;
    while(x < max_x)
    {
        if (map[0][x] != '1')
        {   
            write(1, "Map invalid - Top_Walls", 23);
            return (0);
        }
        x++;
    }
    return (1);
}

static int scan_left_wall(char **map, int max_y)
{
    int y;

    y = 0;
    while(y < max_y)
    {
        if (map[y][0] != '1')
        {   
            write(1, "Map invalid - Left_Walls", 24);
            return (0);
        }
        y++;
    }
    return (1);
}

static int scan_right_wall(char **map, int max_x, int max_y)
{
    int y;
    
    y = 0;

    while(y < max_y)
    {
        if (map[y][max_x - 1] != '1')
        {   
            write(1, "Map invalid - Right_Walls", 25);
            return (0);
        }
        y++;
    }
    return (1);
}

static int scan_bot_wall(char **map, int max_y, int max_x)
{
    int x;
    
    x = 0;
    while(x < max_x)
    {
        if (map[max_y - 1][x] != '1')
        {   
            write(1, "Map invalid - Bot_Walls", 23);
            return (0);
        }
        x++;
    }
    return (1);
}

void  check_walls(t_data *img)
{
    if (!img->map || !**img->map)
    {
        write(1, "Map invalid - check_walls", 25);
        exit(EXIT_FAILURE);
    }
    img->x = count_characters(img->map[0]);
    if (!scan_top_wall(img->map, img->x) || !scan_left_wall(img->map, img->y)
        || !scan_right_wall(img->map, img->x, img->y) 
        || !scan_bot_wall(img->map, img->y, img->x))
    {
        free_map(img);
        exit(EXIT_FAILURE);
    }
}
