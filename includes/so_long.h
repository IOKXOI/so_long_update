/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:30:40 by iok               #+#    #+#             */
/*   Updated: 2022/08/25 20:39:47 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10
# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define TOP 119
# define ESC 65307
# define ANIM_FRAME 1000
# define ANIM_LIMIT 2000


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

typedef struct s_enemies
{
	struct s_enemies	*first;
	int					id;
	int					x_pos;
	int					y_pos;
	int					direction;
	int					once;
	int					i;
	int					anim_up;
	int					random_action;
	int					fram_one;
	int					fram_two;
	int					fram_three;
	int					fram_four;
	struct s_enemies	*last;
	struct s_enemies	*next;
} t_enemies;

typedef struct s_card
{
	struct s_card	*first;
	int				id;
	int				x_pos;
	int				y_pos;
	int				fram_one;
	int				fram_two;
	struct s_card	*last;
	struct s_card	*next;
} t_card;

typedef struct s_data
{
    void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x_offset;
	int			y_offset;
	void		*window;
	void		*mlx;
	int			width;
	int			height;
	char		*ground;
	char		*wall;
	char		*chicken;
	char		*portal;
	char		*hero_face;
	char		*hero_face_up;
	char		*hero_back;
	char		*hero_back_up;
	char		*hero_left;
	char		*hero_left_up;
	char		*hero_right;
	char		*hero_right_up;
	int			direction;
	int			mooves;
	int			mooves_displayed;
	int			open_exit;
	char		**map;
	int			y;
	int			x;
	int			x_hero;
	int			y_hero;
	int			x_exit;
	int			y_exit;
	int			collectible;
	int			hero;
	int			exit;
	int			monster;
	t_enemies	*enemies;
	char		*hisoka_right1;
	char		*hisoka_rightwalk1;
	char		*hisoka_rightwalk2;
	char		*hisoka_rightwalk3;
	char		*hisoka_rightwalk4;
	char		*hisoka_attackright3;
	char		*hisoka_attackrightcard6;
	char		*hisoka_left1;
	char		*hisoka_leftwalk1;
	char		*hisoka_leftwalk2;
	char		*hisoka_leftwalk3;
	char		*hisoka_leftwalk4;
	char		*hisoka_attackleft3;
	char		*hisoka_attackleftcard6;
	char		*card_right1;
	char		*card_right2;
	char		*card_left1;
	char		*card_left2;
	int 		i;
	int			anim;
} t_data;


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

///INIT /////////////////////////////////////////////////////////////
void	init_struct(t_data *img);
void	init_enemy_struct(t_enemies *enemies);
void	init_struct(t_data *img);
/////////////////////////////////////////////////////////////////////

///CHECKS ///////////////////////////////////////////////////////////
void	check_walls(t_data *img);
int		count_characters(char *s1);
int		check_elements(t_data *img);
void	check_arg(int argc, char *argv);
int		check_init(t_data *img);
int		check_open(char *map_ber);
/////////////////////////////////////////////////////////////////////


// CONVERTMAP ///////////////////////////////////////////////////////
void	check_convert_and_scan_map(t_data *img, char *argv);
int		scan_elements(t_data *img);
/////////////////////////////////////////////////////////////////////

// DISPLAY //////////////////////////////////////////////////////////
int		display_map(t_data *img);
void	display_stationary(t_data *img);
void	print_hero(t_data *img);
void	print_exit(t_data *img);
void	print_static_hisoka(t_data *img, t_enemies *this_enemy);
void	display_moove(t_data *img);
/////////////////////////////////////////////////////////////////////

// FREE /////////////////////////////////////////////////////////////
void	free_ressources(t_data *img);
void	free_enemies_ressources(t_data *img);
void	free_map(t_data *img);
void	free_list(t_data *img);
int		error(char *str);
int		destroy(t_data *img);
/////////////////////////////////////////////////////////////////////

void	add_enemies(t_data *img, int x, int y);
void	print_enemy(t_data *img);
void	gg_wp(t_data *img);
// MOOVES ///////////////////////////////////////////////////////////
int		which_key(int keycode, t_data *img);
int		moove_enemy_left(t_data *img, t_enemies *this_enemy);
int		moove_enemy_right(t_data *img, t_enemies *this_enemy);
int		moove_enemy_top(t_data *img, t_enemies *this_enemy);
int		moove_enemy_down(t_data *img, t_enemies *this_enemy);
void	hisokill(t_data *img, t_enemies *this_enemy);
size_t	random_number(t_data *img, t_enemies *this_enemy);
void	init_ressources_and_check(t_data *img);
int		look_for_this_action(t_data *img, t_enemies *this_enemy);


void print_struct(t_enemies *enemy);
void printtab(t_data *img, char **tab, int x_max, int y_max);

# endif
