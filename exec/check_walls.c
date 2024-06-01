/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:28:19 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 11:34:54 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls(t_vars *vars)
{
	double	i;
	double	y;

	vars->x_map = 0;
	vars->y_map = 0;
	i = 0;
	y = 0;
	i = calculate_play_i(vars, i);
	y = calculate_play_y(vars, y);
	if (vars->map[vars->y_map][vars->x_map] == '1')
		return (1);
	return (0);
}

int	check_walls_ray(t_vars *vars)
{
	double	i;
	double	y;

	vars->x_map = 0;
	vars->y_map = 0;
	i = 0;
	y = 0;
	i = calculate_i(vars, i);
	y = calculate_y(vars, y);
	if (vars->map[vars->y_map][vars->x_map] == '1')
	{
		if (vars->play_x < vars->wall_hit_x && check_px_wall(vars,
				vars->wall_hit_x - 1, vars->wall_hit_y) == 0)
			return (WEST);
		else if (vars->play_x > vars->wall_hit_x && check_px_wall(vars,
				vars->wall_hit_x + 1, vars->wall_hit_y) == 0)
			return (EAST);
		else if (vars->play_y < vars->wall_hit_y && check_px_wall(vars,
				vars->wall_hit_x, vars->wall_hit_y - 1) == 0)
			return (SOUTH);
		else if (vars->play_y > vars->wall_hit_y && check_px_wall(vars,
				vars->wall_hit_x, vars->wall_hit_y + 1) == 0)
			return (NORTH);
	}
	return (0);
}

void	check_diagonals_path(t_vars *vars, double i, double y)
{
	if ((vars->incx < 0 && vars->incy < 0) && (vars->x_map > 0
			&& vars->y_map > 0))
		check_no(vars, i, y);
	else if ((vars->incx > 0 && vars->incy < 0) && (vars->x_map > 0
			&& vars->y_map > 0))
		check_ne(vars, i, y);
	else if ((vars->incx < 0 && vars->incy > 0) && (vars->x_map > 0
			&& vars->y_map > 0))
		check_so(vars, i, y);
	else if ((vars->incx > 0 && vars->incy > 0) && (vars->x_map > 0
			&& vars->y_map > 0))
		check_se(vars, i, y);
}

int	check_walls_path(t_vars *vars)
{
	double	i;
	double	y;

	vars->x_map = 0;
	vars->y_map = 0;
	vars->diagonals = 0;
	i = 0;
	y = 0;
	i = calculate_i(vars, i);
	y = calculate_y(vars, y);
	check_diagonals_path(vars, i, y);
	if (vars->map[vars->y_map][vars->x_map] == '1' || vars->diagonals == 1)
	{
		vars->wall_hit_x = vars->ray_x;
		vars->wall_hit_y = vars->ray_y;
		return (1);
	}
	return (0);
}
