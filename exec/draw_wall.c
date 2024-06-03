/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:57:47 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/03 23:21:51 by marvin           ###   ########.fr       */
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
	(void)distance_to_wall;
	(void)x;


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
	else if (vars->direction == DOOR)
		j = draw_door(vars, distance_to_wall, x, j);
}
void	open_door(t_vars *vars)
{
	double distance;

	vars->angle -= FOV / 2;
	distance = 0;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	ft_draw_line_bresenham(vars);
	distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y
		- vars->play_y, 2));
	if(distance <= 40 && vars->map[vars->y_map][vars->x_map] == 'D')
	{
		vars->map[vars->y_map][vars->x_map] = 'O';
		printf("%c\n", vars->map[vars->y_map][vars->x_map]);
	}
	else if(vars->doorx > 0 && vars->doory > 0)
	{
		vars->map[vars->doory][vars->doorx] = 'D';
		vars->doorx = 0;
		vars->doory = 0;
	}
	vars->angle += FOV / 2;
}