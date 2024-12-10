/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:51:17 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/27 11:51:04 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_exit("Error");
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

void	read_map(char *file_name)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_exit("Error");
	}
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		i = ft_strlen(lines);
		if (lines[i - 1] == '\n')
		{
			lines[--i] = '\0';
		}
		g_var.map_data[g_var.map_size.height] = ft_strdup(lines);
		if (g_var.map_size.height++ == 0)
			g_var.map_size.width = i;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	get_map(char **av)
{
	int	num_lines;

	g_var.map_data = NULL;
	g_var.map_size.height = 0;
	g_var.map_size.width = 0;
	num_lines = get_height(av[1]);
	g_var.map_data = (char **)malloc(sizeof(char *) * num_lines);
	if (!g_var.map_data)
	{
		ft_printf("Error allocation data\n");
		exit(1);
	}
	read_map(av[1]);
}

void	load_map(int row, int col)
{
	if (g_var.map_data[row][col] == '1')
		g_var.img_ptr = mlx_xpm_file_to_image(g_var.mlx, "./img/wall.xpm",
				&g_var.img_size.width, &g_var.img_size.height);
	else if (g_var.map_data[row][col] == '0')
		g_var.img_ptr = mlx_xpm_file_to_image(g_var.mlx, "./img/floor.xpm",
				&g_var.img_size.width, &g_var.img_size.height);
	else if (g_var.map_data[row][col] == 'E')
		g_var.img_ptr = mlx_xpm_file_to_image(g_var.mlx, "./img/exit.xpm",
				&g_var.img_size.width, &g_var.img_size.height);
	else if (g_var.map_data[row][col] == 'C')
		g_var.img_ptr = mlx_xpm_file_to_image(g_var.mlx,
				"./img/collect.xpm",
				&g_var.img_size.width, &g_var.img_size.height);
	else if (g_var.map_data[row][col] == 'P')
		g_var.img_ptr = mlx_xpm_file_to_image(g_var.mlx, g_var.img_spt_path,
				&g_var.img_size.width, &g_var.img_size.height);
	mlx_put_image_to_window(g_var.mlx, g_var.win, g_var.img_ptr,
		SPRITE_W * col,
		SPRITE_H * row);
	mlx_destroy_image(g_var.mlx, g_var.img_ptr);
}

int	draw_map(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_var.map_size.height)
	{
		col = 0;
		while (col < g_var.map_size.width)
		{
			load_map(row, col);
			col++;
		}
		row++;
	}
	return (0);
}
