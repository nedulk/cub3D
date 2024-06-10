/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:44 by dboire            #+#    #+#             */
/*   Updated: 2024/06/10 11:20:21 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	redraw_player(t_vars *vars)
{
	if (check_walls(vars) == 1)
		return ;
	ft_correct_angle(vars);
	draw_rays(vars);
}

void	redraw_tile_and_floor(t_vars *vars, int i, int y)
{
	if (vars->map[i][y] == '1')
		draw_wall_tile(vars);
	else if (vars->map[i][y] == 'D')
		draw_door_tile(vars, 1);
	else if (vars->map[i][y] == 'O')
		draw_door_tile(vars, 0);
	else if (vars->map[i][y] == '0')
	{
		draw_floor_tile(vars);
		vars->y = vars->y0;
	}
	else if (vars->map[i][y] == ' ')
		vars->x += EDGE;
}

void	redraw_grid(t_vars *vars)
{
	int	i;
	int	y;

	i = 0;
	vars->y = 0;
	while (vars->map[i])
	{
		y = 0;
		vars->x = 0;
		vars->y0 = vars->y;
		while (vars->map[i][y])
		{
			redraw_tile_and_floor(vars, i, y);
			y++;
		}
		vars->y += EDGE;
		i++;
	}
	redraw_player(vars);
}

void	redraw_grid_wo_p(t_vars *vars)
{
	int	i;
	int	y;

	i = 0;
	vars->y = 0;
	while (vars->map[i])
	{
		y = 0;
		vars->x = 0;
		vars->y0 = vars->y;
		while (vars->map[i][y])
		{
			redraw_tile_and_floor(vars, i, y);
			y++;
		}
		vars->y += EDGE;
		i++;
	}
}
