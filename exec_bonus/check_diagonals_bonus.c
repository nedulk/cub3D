/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diagonals_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:56 by dboire            #+#    #+#             */
/*   Updated: 2024/06/15 10:01:04 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls_player1(t_vars *vars)
{
	char	map_value_px;
	char	map_value_py;
	char	map_value_mx;

	map_value_px = vars->map[vars->prev_pos_y][vars->prev_pos_x + 1];
	map_value_py = vars->map[vars->prev_pos_y + 1][vars->prev_pos_x];
	map_value_mx = vars->map[vars->prev_pos_y][vars->prev_pos_x - 1];
	if ((map_value_py == '1' || map_value_py == 'D')
		&& (map_value_px == '1' || map_value_px == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	if ((map_value_py == '1' || map_value_py == 'D')
		&& (map_value_mx == '1' || map_value_mx == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y + 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	return (0);
}

int	check_walls_player2(t_vars *vars)
{
	char	map_value_my;
	char	map_value_px;

	map_value_my = vars->map[vars->prev_pos_y - 1][vars->prev_pos_x];
	map_value_px = vars->map[vars->prev_pos_y][vars->prev_pos_x + 1];
	if ((map_value_my == '1' || map_value_my == 'D')
		&& (map_value_px == '1' || map_value_px == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x + 1)
			return (1);
	}
	return (0);
}

int	check_walls_player(t_vars *vars)
{
	char	map_value_my;
	char	map_value_mx;

	map_value_my = vars->map[vars->prev_pos_y - 1][vars->prev_pos_x];
	map_value_mx = vars->map[vars->prev_pos_y][vars->prev_pos_x - 1];
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
	if ((map_value_my == '1' || map_value_my == 'D')
		&& (map_value_mx == '1' || map_value_mx == 'D'))
	{
		if (vars->y_map == vars->prev_pos_y - 1
			&& vars->x_map == vars->prev_pos_x - 1)
			return (1);
	}
	return (0);
}
