/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:45:11 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/27 12:37:46 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dfs(char **data, t_position start, t_position size, int **visited)
{
	t_position	next_positions[4];

	next_positions[0].width = start.width;
	next_positions[0].height = start.height + 1;
	next_positions[1].width = start.width;
	next_positions[1].height = start.height - 1;
	next_positions[2].width = start.width + 1;
	next_positions[2].height = start.height;
	next_positions[3].width = start.width - 1;
	next_positions[3].height = start.height;
	if (start.height < 0 || start.height >= size.height || start.width < 0
		|| start.width >= size.width
		|| data[start.height][start.width] == '1'
		|| visited[start.height][start.width])
		return ;
	visited[start.height][start.width] = 1;
	dfs(data, next_positions[0], size, visited);
	dfs(data, next_positions[1], size, visited);
	dfs(data, next_positions[2], size, visited);
	dfs(data, next_positions[3], size, visited);
}

void	moves(int key)
{
	if ((key == KEY_A)
		&& (g_var.map_data[g_var.i_pos.height][g_var.i_pos.width - 1] == 'E'))
		check_collect();
	else if ((key == KEY_A)
		&& (g_var.map_data[g_var.i_pos.height][g_var.i_pos.width - 1] != '1'))
		move_left();
	if ((key == KEY_D)
		&& (g_var.map_data[g_var.i_pos.height][g_var.i_pos.width + 1] == 'E'))
		check_collect();
	else if ((key == KEY_D)
		&& (g_var.map_data[g_var.i_pos.height][g_var.i_pos.width + 1] != '1'))
		move_right();
	if ((key == KEY_S)
		&& (g_var.map_data[g_var.i_pos.height + 1][g_var.i_pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_S)
		&& (g_var.map_data[g_var.i_pos.height + 1][g_var.i_pos.width] != '1'))
		move_down();
	if ((key == KEY_W)
		&& (g_var.map_data[g_var.i_pos.height - 1][g_var.i_pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_W)
		&& (g_var.map_data[g_var.i_pos.height - 1][g_var.i_pos.width] != '1'))
		move_up();
}

void	initialize(void)
{
	g_var.mlx = NULL;
	g_var.win = NULL;
	g_var.count_collec = 0;
	g_var.count_steps = 0;
	g_var.map_data = NULL;
	g_var.map_size.height = 0;
	g_var.map_size.width = 0;
	g_var.img_ptr = NULL;
	g_var.img_spt_path = "./img/right.xpm";
	g_var.img_size.width = 0;
	g_var.img_size.height = 0;
	g_var.i_pos.width = 0;
	g_var.i_pos.height = 0;
	g_var.img_data = NULL;
}
