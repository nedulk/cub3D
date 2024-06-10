/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diagonals_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:56 by dboire            #+#    #+#             */
/*   Updated: 2024/06/10 14:51:23 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls_player1(t_vars *vars)
{
	if ((vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == '1'
		|| vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == 'D')
		&& (vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == '1'
			|| vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	if ((vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == '1'
		|| vars->map[vars->prev_pos_y + 1][vars->prev_pos_x] == 'D')
		&& (vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == '1'
			|| vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	return (0);
}

int	check_walls_player2(t_vars *vars)
{
	if ((vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == '1'
		|| vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == 'D')
		&& (vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == '1'
			|| vars->map[vars->prev_pos_y][vars->prev_pos_x + 1] == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	return (0);
}

int	check_walls_player(t_vars *vars)
{
	vars->x_map = 0;
	vars->y_map = 0;
	calculate_play_i(vars, 0);
	calculate_play_y(vars, 0);
	if (vars->map[vars->y_map][vars->x_map] == '1'
		|| vars->map[vars->y_map][vars->x_map] == 'D')
		return (1);
	if (check_walls_player1(vars) == 1)
		return (1);
	if (check_walls_player2(vars) == 1)
		return (1);
	if ((vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == '1'
		|| vars->map[vars->prev_pos_y - 1][vars->prev_pos_x] == 'D')
		&& (vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == '1'
			|| vars->map[vars->prev_pos_y][vars->prev_pos_x - 1] == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	return (0);
}
