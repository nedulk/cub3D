/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:47:54 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 20:44:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_absolute_number(double value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

double	ft_sign(double value)
{
	double	i;

	i = 1;
	if (value < 0)
		i = -1;
	return (i);
}

int	ft_draw_line_bresenham(t_vars *vars)
{
	vars->dx = ft_absolute_number(vars->ray_x1 - vars->ray_x0);
	vars->incx = ft_sign(vars->ray_x1 - vars->ray_x0);
	vars->dy = ft_absolute_number(vars->ray_y1 - vars->ray_y0);
	vars->incy = ft_sign(vars->ray_y1 - vars->ray_y0);
	vars->incx /= 5;
	vars->incy /= 5;
	vars->ray_y = vars->ray_y0;
	vars->ray_x = vars->ray_x0;
	if (vars->dx >= vars->dy)
		ft_draw_horizontal(vars);
	else
		ft_draw_vertical(vars);
	return (0);
}

void	ft_draw_horizontal(t_vars *vars)
{
	float	slope;
	float	error;
	float	errorinc;

	slope = 2 * vars->dy;
	error = -vars->dx;
	errorinc = -2 * vars->dx;
	while (1)
	{
		if (check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
		error += slope;
		if (error >= 0)
		{
			vars->ray_y += vars->incy;
			error += errorinc;
		}
		vars->ray_x += vars->incx;
	}
}

void	ft_draw_vertical(t_vars *vars)
{
	float	slope;
	float	error;
	float	errorinc;

	slope = 2 * vars->dx;
	error = -vars->dy;
	errorinc = -2 * vars->dy;
	while (1)
	{
		if (check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
		error += slope;
		if (error >= 0)
		{
			vars->ray_x += vars->incx;
			error += errorinc;
		}
		vars->ray_y += vars->incy;
	}
}
