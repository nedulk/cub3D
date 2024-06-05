/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_i_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:18:40 by dboire            #+#    #+#             */
/*   Updated: 2024/06/05 13:36:02 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calculate_i(t_vars *vars, double i)
{
	while (i < vars->ray_x)
	{
		i += EDGE;
		vars->x_map++;
	}
	i = (i - vars->ray_x) / EDGE;
	if (vars->x_map > 0)
		vars->x_map -= 1;
	vars->pos_x = i;
	return (i);
}

double	calculate_y(t_vars *vars, double y)
{
	while (y < vars->ray_y)
	{
		y += EDGE;
		vars->y_map++;
	}
	y = (y - vars->ray_y) / EDGE;
	if (vars->y_map > 0)
		vars->y_map -= 1;
	vars->pos_y = y;
	return (y);
}

double	calculate_play_i(t_vars *vars, double i)
{
	while (i < vars->play_x)
	{
		i += EDGE;
		vars->x_map++;
	}
	i = (i - vars->play_x) / EDGE;
	if (vars->x_map > 0)
		vars->x_map -= 1;
	return (i);
}

double	calculate_play_y(t_vars *vars, double y)
{
	while (y < vars->play_y)
	{
		y += EDGE;
		vars->y_map++;
	}
	y = (y - vars->play_y) / EDGE;
	if (vars->y_map > 0)
		vars->y_map -= 1;
	return (y);
	if (vars->y_map > 0)
		vars->y_map -= 1;
}
