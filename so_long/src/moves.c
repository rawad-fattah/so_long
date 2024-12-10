/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:48:28 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/08/27 10:39:29 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(void)
{
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = '0';
	g_var.i_pos.width -= 1;
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = 'P';
	g_var.count_steps++;
	g_var.img_spt_path = "./img/left.xpm";
}

void	move_right(void)
{
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = '0';
	g_var.i_pos.width += 1;
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = 'P';
	g_var.count_steps++;
	g_var.img_spt_path = "./img/right.xpm";
}

void	move_up(void)
{
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = '0';
	g_var.i_pos.height -= 1;
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = 'P';
	g_var.count_steps++;
	g_var.img_spt_path = "./img/right.xpm";
}

void	move_down(void)
{
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = '0';
	g_var.i_pos.height += 1;
	g_var.map_data[g_var.i_pos.height][g_var.i_pos.width] = 'P';
	g_var.count_steps++;
	g_var.img_spt_path = "./img/right.xpm";
}

void	check_collect(void)
{
	if (count_collec() == 0)
		free_exit("\e[32m\e[5m\e[1mCONGRATULATIONS \n!!!! You WON !!!!\e[0m\n");
	else
		ft_printf("\e[35m\e[1m ⚠️  Please, collect all the coins!!!\e[0m\n");
}
