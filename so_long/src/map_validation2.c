/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:47:48 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/24 09:48:07 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_position	start_position(void)
{
	t_position	start;
	int			i;
	int			j;

	i = 0;
	start.width = 0;
	start.height = 0;
	while (i < g_var.map_size.height)
	{
		j = 0;
		while (j < g_var.map_size.width)
		{
			if (g_var.map_data[i][j] == 'P')
			{
				start.width = j;
				start.height = i;
			}
			j++;
		}
		i++;
	}
	return (start);
}

void	is_reachable(int **visited, t_position size)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_var.map_size.height)
	{
		j = 0;
		while (j < g_var.map_size.width)
		{
			if ((g_var.map_data[i][j] == 'E' || g_var.map_data[i][j] == 'C')
			&& !visited[i][j])
			{
				if (g_var.map_data[i][j] == 'E')
					reach(visited, size);
				if (g_var.map_data[i][j] == 'C')
					reach(visited, size);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	has_valid_path(void)
{
	int			**visited;
	int			i;
	t_position	start;
	t_position	size;

	size.width = g_var.map_size.width;
	size.height = g_var.map_size.height;
	visited = (int **)malloc(g_var.map_size.height * sizeof(int *));
	if (!visited)
		free_map();
	i = 0;
	while (i < g_var.map_size.height)
	{
		visited[i] = (int *)ft_calloc(g_var.map_size.width, sizeof(int));
		i++;
	}
	start = start_position();
	dfs(g_var.map_data, start, size, visited);
	is_reachable(visited, size);
	free_visited(visited, size);
}

void	reach(int **visited, t_position size)
{
	ft_printf("error no path");
	free_map();
	free_visited(visited, size);
	exit(1);
}
