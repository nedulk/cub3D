/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:47:54 by dboire            #+#    #+#             */
/*   Updated: 2024/05/29 15:20:55 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

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
	// printf("distance : %f", distance);
	vars->incx /= 3;
	vars->incy /= 3;
	vars->ray_y = vars->ray_y0;
	vars->ray_x = vars->ray_x0;
	if (vars->dx == 0)
	{
		ft_draw_line_y(vars);
	}
	else if (vars->dy == 0)
	{
		ft_draw_line_x(vars);
	}
	else if (vars->dx >= vars->dy)
	{
		ft_draw_horizontal(vars);
	}
	else
	{
		ft_draw_vertical(vars);
	}
	return (0);
}

void	ft_draw_line_x(t_vars *vars)
{

	while(1) //while(vars->ray_x != vars->ray_x1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		if(vars->draw == 125 || vars -> draw == 0 || vars -> draw == 249)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0x0000FF00);
		// else
		// 	my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
		vars->ray_x += vars->incx;
	}
}

void	ft_draw_line_y(t_vars *vars)
{
	while (1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		if(vars->draw == 125 || vars -> draw == 0 || vars -> draw == 249)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0x0000FF00);
		// else
		// 	my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
		vars->ray_y += vars->incy;
	}
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
		if(check_walls_path(vars) == 1)
			break ;
		if(vars->draw == 125 || vars -> draw == 0 || vars -> draw == 249)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0x0000FF00);
		// else
		// 	my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
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
		if(check_walls_path(vars) == 1)
			break ;
		if(vars->draw == 125 || vars -> draw == 0 || vars -> draw == 249)
			my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0x0000FF00);
		// else
		// 	my_mlx_pixel_put(vars, vars->ray_x, vars->ray_y, 0xFFFF0000);
		error += slope;
		if (error >= 0)
		{
			vars->ray_x += vars->incx;
			error += errorinc;
		}
		vars->ray_y += vars->incy;
	}
}
