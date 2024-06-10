/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:47:54 by dboire            #+#    #+#             */
/*   Updated: 2024/06/10 17:51:06 by kprigent         ###   ########.fr       */
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

int	ft_draw_line_bresenham(t_vars *vars, int put)
{
	double	diff_x;
	double	diff_y;

	diff_x = vars->ray_x1 - vars->ray_x0;
	diff_y = vars->ray_y1 - vars->ray_y0;
	vars->dx = ft_absolute_number(diff_x);
	vars->incx = ft_sign(diff_x);
	vars->dy = ft_absolute_number(diff_y);
	vars->incy = ft_sign(diff_y);
	vars->incx /= 5;
	vars->incy /= 5;
	vars->ray_y = vars->ray_y0;
	vars->ray_x = vars->ray_x0;
	if (vars->dx >= vars->dy)
		ft_draw_horizontal(vars, put);
	else
		ft_draw_vertical(vars, put);
	return (0);
}

void	ft_draw_horizontal(t_vars *vars, int put)
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
		if ((int)vars->draw % RAYS == 0 && vars->map_press == 1 && put == 1)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFD3D3D3);
		error += slope;
		if (error >= 0)
		{
			vars->ray_y += vars->incy;
			error += errorinc;
		}
		vars->ray_x += vars->incx;
	}
}

void	ft_draw_vertical(t_vars *vars, int put)
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
		if ((int)vars->draw % RAYS == 0 && vars->map_press == 1 && put == 1)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFD3D3D3);
		error += slope;
		if (error >= 0)
		{
			vars->ray_x += vars->incx;
			error += errorinc;
		}
		vars->ray_y += vars->incy;
	}
}
