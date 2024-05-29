/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/29 20:14:19 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void rotation_matrix(t_vars *vars)
{
	double radian;
	double cos_a;
	double sin_a;
	double dx;
	double dy;


	radian = 0;
	cos_a = 0;
	sin_a = 0;
	dx = 0;
	dy = 0;
	radian = vars->angle *  (PI / 180);
	cos_a = cos(radian);
	sin_a = sin(radian);
	dx = 1;
	dy = 1;

	vars->rotate_x1 = (dx * cos_a) - (dy * sin_a);
	vars->rotate_y1 =(dx * sin_a) + (dy * cos_a);
}

double calculate_wall_height(t_vars *vars, double distance, double ray_angle)
{
    double wall_height;
	(void)vars;
	
    double corrected_distance = distance * cos((ray_angle - vars->angle) * (PI / 180.0));
    wall_height = (HEIGHT/ corrected_distance) * 20;
    return (wall_height);
}

void	draw_rays(t_vars *vars)
{
	double	angle_step;
	double	distance = 0;
	// int	y;
	vars->rays_number = 800.0;
	// float x = 0;
	float column_end;
	float column_start;
	// double angle;

	// y = 1919;
	angle_step = 60 / vars->rays_number;
	vars->angle -= 60;
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
	// angle = vars->angle;
	column_start = 0;
	vars->draw = 0;
	while(vars->draw < vars->rays_number)
	{
		//origine du rayon
		vars->ray_x0 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		
		//angle du rayon pour determiner la direction du rayon
		if (vars->ray_x0 > 0)
		{
			vars->ray_x1 = cos((vars->angle * PI) / 180) + vars->ray_x0;
			vars->ray_y1 = sin((vars->angle * PI) / 180) + vars->ray_x0;
		}
		else
		{
			vars->ray_x1 = cos((vars->angle * PI) / 180);
			vars->ray_y1 = sin((vars->angle * PI) / 180);
		}
		rotation_matrix(vars);
		// printf("r_x1 : %f\n", vars->rotate_x1);
		// printf("r_y1 : %f\n", vars->rotate_y1);
		//nouvelle position pour angle du rayon
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		// printf("x: %f\n", vars->wall_hit_x);
		// printf("y: %f\n", vars->wall_hit_y);
		// exit(0);
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y - vars->play_y, 2));
		int h = calculate_wall_height(vars, distance, vars->angle);
        column_end = (vars->draw + 1) * (WIDTH / vars->rays_number);
        while(column_start < column_end)
        {
			draw_wall(vars, column_start, h, distance);
			column_start++;
		}
		vars->draw++;
		vars->angle += angle_step;
		if (vars->angle < 0)
			vars->angle += 360.0;
		if (vars->angle >= 360)
			vars->angle -= 360.0;
	}
	// vars->angle -= 60;
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
}
