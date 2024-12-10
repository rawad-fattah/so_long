/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:45:44 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/24 09:45:55 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(void)
{
	int	i;

	i = 0;
	if (g_var.mlx)
	{
		mlx_destroy_window(g_var.mlx, g_var.win);
		mlx_destroy_display(g_var.mlx);
	}
	free(g_var.mlx);
	while (i < g_var.map_size.height)
	{
		free(g_var.map_data[i]);
		i++;
	}
	free(g_var.map_data);
}

void	free_exit(char	*sms)
{
	ft_printf("%s", sms);
	free_map();
	exit(EXIT_FAILURE);
}

void	free_visited(int **visited, t_position size)
{
	int	i;

	i = 0;
	while (i < size.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	mlx_close(void)
{
	free_exit("\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}
