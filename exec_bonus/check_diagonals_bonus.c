/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diagonals_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:56 by dboire            #+#    #+#             */
/*   Updated: 2024/06/10 14:44:19 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls_player1(t_vars *vars)
{
	if (vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == '1'
		&& vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == '1')
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	if (vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == '1'
		&& vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == '1')
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	if (vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == '1'
		&& vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == '1')
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	return (0);
}

int	check_walls_player(t_vars *vars)
{
	double	i;
	double	y;

	i = 0;
	y = 0;
	vars->x_map = 0;
	vars->y_map = 0;
	i = calculate_play_i(vars, i);
	y = calculate_play_y(vars, y);
	if (vars->map[vars->y_map][vars->x_map] == '1'
		|| vars->map[vars->y_map][vars->x_map] == 'D')
		return (1);
	if (check_walls_player1(vars) == 1)
		return (1);
	if (vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == '1'
		&& vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == '1')
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	return (0);
}
