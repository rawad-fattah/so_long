/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:47:04 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/24 09:47:24 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walls_valide(void)
{
	int	i;

	i = 0;
	while (i < g_var.map_size.width)
	{
		if (g_var.map_data[0][i] != '1' || g_var.map_data[g_var.map_size.height
			- 1][i] != '1')
			free_exit("invalid map\n");
		i++;
	}
	i = 0;
	while (i < g_var.map_size.height)
	{
		if (g_var.map_data[i][0] != '1'
			|| g_var.map_data[i][g_var.map_size.width - 1] != '1')
			free_exit("invalid map\n");
		i++;
	}
}

void	is_rectangular(void)
{
	int	i;

	i = 0;
	while (i < g_var.map_size.height)
	{
		if ((int)ft_strlen(g_var.map_data[i]) != g_var.map_size.width)
			free_exit("not rectangular");
		i++;
	}
}

int	is_valid(char c)
{
	return (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0');
}

void	collectibale_validation(void)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (i < g_var.map_size.height)
	{
		j = 0;
		while (j < g_var.map_size.width)
		{
			if (!is_valid(g_var.map_data[i][j]))
				free_exit("error other carecters");
			if (g_var.map_data[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (collect == 0)
		free_exit("no collectables");
	g_var.count_collec = collect;
}
