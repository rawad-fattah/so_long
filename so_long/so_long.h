/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:54:58 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/27 11:43:48 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MinilibX/mlx.h"
# include "ft_printf/includes/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define WIN_WIDTH 80
# define WIN_HEIGHT 600
# define TILE_SIZE 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define SPRITE_H 50
# define SPRITE_W 50
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef struct l_position
{
	int	width;
	int	height;
}	t_position;

typedef struct s_game_data
{
	void		*mlx;
	void		*win;
	int			count_collec;
	int			count_steps;
	t_position	map_size;
	char		**map_data;
	void		*img_ptr;
	char		*img_spt_path;
	t_position	img_size;
	t_position	i_pos;
	void		*img_data;
}	t_game_data;

extern t_game_data	g_var;

void		get_map(char **av);
void		initialize(void);
void		read_map(char *file_name);
void		check_map(void);
void		collectibale_validation(void);
void		contains_one_exit(void);
int			is_valid(char c);
void		is_rectangular(void);
void		walls_valide(void);
void		dfs(char **data, t_position start, t_position size, int **visited);
void		has_valid_path(void);
void		free_visited(int **visited, t_position size);
void		is_reachable(int **visited, t_position size);
void		free_visited(int **visited, t_position size);
void		free_exit(char		*sms);
void		free_map(void);
void		reach(int **visited, t_position size);
int			mlx_close(void);
void		init_position(void);
void		load_map(int row, int col);
void		moves(int key);
void		move_left(void);
void		move_right(void);
void		move_up(void);
void		move_down(void);
void		check_collect(void);
void		print_steps(void);
int			get_height(char *file_name);
int			key_press(int key);
int			count_collec(void);
int			draw_map(void);
t_position	start_position(void);

#endif