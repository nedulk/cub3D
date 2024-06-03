/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/06/03 18:41:44 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotation_matrix(t_vars *vars)
{
	double	radian;
	double	cos_a;
	double	sin_a;
	double	dx;
	double	dy;

	radian = 0;
	cos_a = 0;
	sin_a = 0;
	dx = vars->ray_x1 - vars->ray_x0;
	dy = vars->ray_y1 - vars->ray_y0;
	radian = vars->angle * (PI / 180);
	cos_a = cos(radian);
	sin_a = sin(radian);
	dx = 1;
	dy = 0;
	vars->rotate_x1 = (dx * cos_a) - (dy * sin_a);
	vars->rotate_y1 = (dx * sin_a) + (dy * cos_a);
	vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
	vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
}

double	calculate_wall_height(t_vars *vars, double distance, double ray_angle)
{
	double	wall_height;
	double	corrected_distance;

	corrected_distance = distance * cos((ray_angle - vars->angle) * (PI
				/ 180.0));
	wall_height = (HEIGHT / corrected_distance) * 20;
	return (wall_height);
}

void	ft_correct_angle(t_vars *vars)
{
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
}

void	define_fov(t_vars *vars)
{
	vars->draw = 0;
	vars->rays_number = 1920;
	vars->angle_step = FOV / vars->rays_number;
	vars->angle -= FOV;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
}

void draw_celing(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			my_mlx_pixel_put(vars, i, j, vars->celing_color);
			j++;
		}
		i++;
	}
}

void draw_floor(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT / 2;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(vars, i, j, vars->floor_color);
			j++;
		}
		i++;
	}
}
void	draw_rays(t_vars *vars)
{
	double	distance;
	float	column_end;
	float	column_start;
	int		h;

	column_start = 0;
	distance = 0;
	define_fov(vars);
	ft_correct_angle(vars);
	draw_celing(vars);
	draw_floor(vars);
	while (vars->draw < vars->rays_number)
	{
		rotation_matrix(vars);
		ft_draw_line_bresenham(vars);
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y
					- vars->play_y, 2));
		h = calculate_wall_height(vars, distance, vars->angle);
		column_end = (vars->draw + 1) * (WIDTH / vars->rays_number);
		while (column_start <= column_end)
			draw_wall(vars, column_start++, h, distance);
		vars->draw++;
		vars->angle += vars->angle_step;
		ft_correct_angle(vars);
	}
}
