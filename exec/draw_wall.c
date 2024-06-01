/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:57:47 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/01 13:50:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_draw(t_vars *vars, int wall_height)
{
	vars->draw_start = (HEIGHT / 2) - wall_height;
	vars->draw_end = (HEIGHT / 2) + wall_height;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	if (vars->draw_end >= HEIGHT)
		vars->draw_end = HEIGHT - 1;
	vars->direction = check_walls_ray(vars);
}

void	draw_wall(t_vars *vars, int x, int wall_height, double distance_to_wall)
{
	int	j;

	j = vars->draw_start;
	init_draw(vars, wall_height);
	if (vars->direction == NORTH)
		j = draw_north_wall(vars, distance_to_wall, x, j);
	else if (vars->direction == EAST)
		j = draw_east_wall(vars, distance_to_wall, x, j);
	else if (vars->direction == SOUTH)
		j = draw_south_wall(vars, distance_to_wall, x, j);
	else if (vars->direction == WEST)
		j = draw_west_wall(vars, distance_to_wall, x, j);
	while (j <= HEIGHT)
	{
		my_mlx_pixel_put(vars, x, j, vars->floor_color);
		j++;
	}
	j = vars->draw_start;
	while (j >= 0)
	{
		my_mlx_pixel_put(vars, x, j, vars->celing_color);
		j--;
	}
}
