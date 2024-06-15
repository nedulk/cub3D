/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/06/15 10:14:10 by dboire           ###   ########.fr       */
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
	radian = vars->angle * (PI / 180);
	cos_a = cos(radian);
	sin_a = sin(radian);
	dx = SPEED;
	dy = 0;
	vars->rotate_x1 = (dx * cos_a) - (dy * sin_a);
	vars->rotate_y1 = (dx * sin_a) + (dy * cos_a);
	vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
	vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
}

void	draw_celing(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (SKY != 0)
	{
		draw_sky_img(vars, vars->angle);
		return ;
	}
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

void	draw_floor(t_vars *vars)
{
	int	i;
	int	j;

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

void	init_rays(t_vars *vars)
{
	define_fov(vars);
	ft_correct_angle(vars);
	draw_celing(vars);
	draw_floor(vars);
}

void	draw_rays(t_vars *vars)
{
	double	distance;
	float	column_start;
	int		h;

	column_start = 0;
	distance = 0;
	init_rays(vars);
	while (vars->draw < vars->rays_number)
	{
		rotation_matrix(vars);
		ft_draw_line_bresenham(vars, 0);
		if (vars->play_y - vars->ray_y == 30 && vars->ray_x - vars->play_x == 0)
		{
			vars->play_y += 2;
			vars->play_x += 2;
		}
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y
					- vars->play_y, 2));
		h = (HEIGHT / distance) * 20.;
		draw_wall(vars, column_start++, h, distance);
		vars->draw++;
		vars->angle += vars->angle_step;
		ft_correct_angle(vars);
	}
}
