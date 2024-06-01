/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:35:32 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 13:51:27 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	loop_draw_grid(t_vars *vars, int i, int y)
{
	if (vars->map[i][y] == '1')
		draw_wall_tile(vars);
	else if (vars->map[i][y] == '0')
	{
		draw_floor_tile(vars);
		vars->y = vars->y0;
	}
	else if (vars->map[i][y] == ' ')
		vars->x += EDGE;
	if (vars->map[i][y] == 'N')
	{
		draw_player(vars);
		vars->map[i][y] = '0';
		vars->y = vars->y0;
		vars->x += EDGE;
	}
}

void	draw_grid(t_vars *vars)
{
	int	i;
	int	y;

	i = 0;
	while (vars->map[i])
	{
		y = 0;
		vars->x = 0;
		vars->y0 = vars->y;
		while (vars->map[i][y])
		{
			loop_draw_grid(vars, i, y);
			y++;
		}
		vars->y += EDGE;
		i++;
	}
}
