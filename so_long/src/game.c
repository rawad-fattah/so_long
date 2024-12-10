/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:46:11 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/24 09:46:31 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_var.map_size.height)
	{
		j = 0;
		while (j < g_var.map_size.width)
		{
			if (g_var.map_data[i][j] == 'P')
			{
				g_var.i_pos.width = j;
				g_var.i_pos.height = i;
			}
			j++;
		}
		i++;
	}
}

void	contains_one_exit(void)
{
	int	exit_count;
	int	start_count;
	int	i;
	int	j;

	start_count = 0;
	exit_count = 0;
	i = 0;
	while (i < g_var.map_size.height)
	{
		j = 0;
		while (j < g_var.map_size.width)
		{
			if (g_var.map_data[i][j] == 'E')
				exit_count++;
			if (g_var.map_data[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count != 1 || exit_count != 1)
		free_exit("error many E or P");
}

void	check_map(void)
{
	walls_valide();
	is_rectangular();
	collectibale_validation();
	contains_one_exit();
	has_valid_path();
}
