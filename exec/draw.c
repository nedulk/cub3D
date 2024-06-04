/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:41:55 by dboire            #+#    #+#             */
/*   Updated: 2024/06/04 16:43:41 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_vars *vars)
{
	vars->play_x = vars->x + EDGE / 2;
	vars->play_y = vars->y + EDGE / 2;
	draw_rays(vars);
}

void	draw_floor_tile(t_vars *vars)
{
	vars->x0 = vars->x;
	vars->x1 = vars->x + EDGE;
	vars->y0 = vars->y;
	vars->y1 = vars->y + EDGE;
	while (vars->x < vars->x1)
	{
		if (vars->map_press == 1)
			my_mlx_pixel_put(vars, vars->x, vars->y0, 0x00FFFFFF);
		vars->x++;
	}
	while (vars->y < vars->y1 && vars->map_press == 1)
	{
		if (vars->map_press == 1)
			my_mlx_pixel_put(vars, vars->x, vars->y, 0x00FFFFFF);
		vars->y++;
	}
}

void draw_door_tile(t_vars *vars, int state)
{
	int color;
	
	if (state == 1)
		color = 0x00FFA500;
	else if (state == 0)
		color = 0x000FF000;	
	vars->x0 = vars->x;
	vars->x1 = vars->x + EDGE;
	vars->y = vars->y0;
	vars->y1 = vars->y + EDGE;
	while (vars->y < vars->y1)
	{
		vars->x = vars->x0;
		while (vars->x < vars->x1)
		{
			if (vars->map_press == 1)
				my_mlx_pixel_put(vars, vars->x, vars->y, color);
			vars->x++;
		}
		vars->y++;
	}
	vars->y = vars->y0;
}

void	draw_wall_tile(t_vars *vars)
{
	vars->x0 = vars->x;
	vars->x1 = vars->x + EDGE;
	vars->y = vars->y0;
	vars->y1 = vars->y + EDGE;
	while (vars->y < vars->y1)
	{
		vars->x = vars->x0;
		while (vars->x < vars->x1)
		{
			if (vars->map_press == 1)
				my_mlx_pixel_put(vars, vars->x, vars->y, 0x00FFFFFF);
			vars->x++;
		}
		vars->y++;
	}
	vars->y = vars->y0;
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
