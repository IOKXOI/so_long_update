/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:58:04 by iok               #+#    #+#             */
/*   Updated: 2022/08/26 06:39:33 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	img;

	check_arg(argc, argv[1]);
	init_struct(& img);
	check_convert_and_scan_map(&img, argv[1]);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.x * 72, img.y * 72, "so_long");
	img.img = mlx_new_image(img.mlx, img.x * 72, img.y * 72);
	init_ressources_and_check(&img);
	display_stationary(&img);
	mlx_hook(img.window, 2, (1L << 0), which_key, &img);
	mlx_loop_hook(img.mlx, display_hero, &img);
	mlx_hook(img.window, 17, (1L << 17), destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
