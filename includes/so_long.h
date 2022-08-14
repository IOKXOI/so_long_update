/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:30:40 by iok               #+#    #+#             */
/*   Updated: 2022/08/14 09:45:37 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10
# define TRUE 1
# define FALSE 0


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

typedef struct s_data
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_offset;
	int		y_offset;
	void	*window;
	void	*mlx;
	int		width;
	int		height;
	char	*ground;
	char	*wall;
	char	*chicken;
	char	*portal;
	char	*hero_face;
	char	*hero_face_up;
	char	*hero_back;
	char	*hero_back_up;
	char	*hero_left;
	char	*hero_left_up;
	char	*hero_right;
	char	*hero_right_up;
	int		direction;
	int		open_exit;
	char	**map;
	int		y;
	int		x;
	int		x_hero;
	int		y_hero;
	int		x_exit;
	int		y_exit;
	int		collectible;
	int		hero;
	int		exit;
	int		monster;
	int 	i;
	size_t	anim;
} t_data;

typedef struct s_map
{

} t_map;

typedef struct s_to_free
{
	char	**map;
	int		map_limit;
} t_to_free;

// GNL FONCTIONS ////////////////////////////////////////////////////
void	*ft_memmove(void *dest, const void *src, size_t size);
char	*stop_condition(ssize_t nb, char *valid_line);
char	*extract_str(char *buffer, ssize_t *new_line);
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *actual_line, char *temp);
char	*ft_strndup(char *buffer, size_t n);
size_t	ft_strlen(const char *str);
ssize_t	fill_buffer(int fd, char *buffer);
/////////////////////////////////////////////////////////////////////

///CHECKS ///////////////////////////////////////////////////////////
void	check_walls(t_data *img);
int		count_characters(char *s1);
int		check_elements(t_data *img);
void	check_arg(int argc, char *argv);
int		check_init(t_data *img);

/////////////////////////////////////////////////////////////////////


// CONVERTMAP ///////////////////////////////////////////////////////
char	**check_convert_and_scan_map(t_data *img, char *argv);
int		scan_elements(t_data *img);

/////////////////////////////////////////////////////////////////////

// DISPLAY //////////////////////////////////////////////////////////
int		display_map(t_data *img);
void	print_hero(t_data *img);	
void	print_exit(t_data *img);
/////////////////////////////////////////////////////////////////////

// FREE /////////////////////////////////////////////////////////////
void	free_ressources(t_data *img);
void	free_map(t_data *img);
int		error(char *str);

// MOOVES ///////////////////////////////////////////////////////////
int		which_key(int keycode, t_data *img);

void	garbage_removal(t_to_free *garbage_collector, int y_limit);

# endif
