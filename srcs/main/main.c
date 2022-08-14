/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:58:04 by iok               #+#    #+#             */
/*   Updated: 2022/08/14 10:02:24 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void *destroy(img)
{
  free_map(&img);
  
}
/*
int main(int argc, char **argv)
{
    void*   mlx;
    char*   mlx_win;
    t_data  img;
    t_map_data  data_map;
    t_to_free   garbage_collector;
    int   x = 0;
    int   y = 0;
    void *map;

    data_img.map = mapfile_to_tab(argv[1], &map);
    //garbage_collector.map = data_img.map;
    //garbage_collector.map_limit = data_img.y;
    while (y < data_img.y)
    {
      while (data_img.map[y][x])
      {
        x++;
      }
      
      x = 0;
      y++;
    }
    garbage_removal(&garbage_collector, data_img.y);
    
    
    
    
    if (!data_img.map)
      
    mlx = mlx_init();
    
    img.img = mlx_new_image(mlx, 16 * x, 16 * y);
    mlx_win = mlx_new_window(mlx, 16 * y, 16 * x, "so_long");
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
   return (0);
}

*/

int print_hero_test(t_data *img)
{
  if (img->anim < 10000)
		mlx_put_image_to_window(img->mlx, img->window, img->hero_left, 6 * 72, 3 * 72);
	else
		mlx_put_image_to_window(img->mlx, img->window, img->hero_left_up, 6 * 72, 3 * 72);
	img->anim++;
	if (img->anim > 20000)
		img->anim = 0;
}

////

int main(int argc, char **argv)
{
  t_data img;
  int i = 0;
  
  img.monster = 0;
  img.exit = 0;
  img.hero = 0;
  img.anim = 0;
  img.collectible = 0;
  img.x_offset = 0;
  img.y_offset = 0;
  img.direction = 97;
  img.open_exit = 0;

  check_arg(argc, argv[1]);
  check_convert_and_scan_map(&img, argv[1]);
  init_ressources(&img);
  
  img.mlx = mlx_init();
  img.window = mlx_new_window(img.mlx, img.x * 72, img.y * 72, "le jeu");
  mlx_loop_hook(img.mlx, display_map, &img);
  mlx_hook(img.window, 2, (1L << 0), which_key, &img);
  mlx_loop(img.mlx);

  //ft_check_struct(&map);
  




  
  free_map(&img);
  return (0);
}
