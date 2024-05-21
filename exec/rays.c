/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/21 11:35:39 by dboire           ###   ########.fr       */
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
	dx = vars->ray_x1 - vars->ray_x0;
	dy = vars->ray_y1 - vars->ray_y0;
	vars->rotate_x1 = (dx * cos_a) - (dy * sin_a);
	vars->rotate_y1 =(dx * sin_a) + (dy * cos_a);
}

double calculate_wall_height(t_vars *vars, double distance, double ray_angle)
{
    double wall_height;
	(void)vars;
	
    double corrected_distance = distance * (cos(((ray_angle * (PI / 180.0)) - (vars->angle * (PI / 180.0))) * PI / 180.0));
    wall_height = (HEIGHT / (corrected_distance));
    // pas plus grand que la hauteur de l'écran
    if (wall_height > HEIGHT)
        wall_height = HEIGHT;
    printf("Wall height : %f ", wall_height);
    printf("Ray angle : %f ", ray_angle);
    printf("Angle : %f ", vars->angle);
    printf("Distance : %f ", distance);
    printf("Corrected distance : %f\n", corrected_distance);


   
    return (wall_height);
}
void draw_wall(t_vars *vars, double x, double wall_height)
{
	// int centerX = WIDTH / 2;
	// double centerY = HEIGHT;

	double draw_start = 540;
	if(draw_start < 0)
		draw_start = 0;
	double draw_end = 540 + wall_height;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	double wall_color = 0x00FF0000;
	double j = draw_start;
	printf("j : %f\n", j);
	printf("draw_end : %f\n", draw_end);
	while (j < draw_end)
	{
		my_mlx_pixel_put(vars, x, j++, wall_color);;
	}
}
void	draw_rays(t_vars *vars)
{
	int	i;
	double	angle;
	double	distance;
	int	y;
	int x = WIDTH / 5;

	y = 1400;
	i = 0;
	angle = vars->angle - (y / 2);
	while(i < y)
	{
		vars->ray_x0 = vars->play_x;
		vars->ray_x0 = vars->play_x;
		double ray_angle = vars->angle + i * 0.1;
		vars->ray_y0 = vars->play_y;
		vars->ray_x1 = cos(vars->angle * PI / 180);
		vars->ray_y1 = sin(vars->angle * PI / 180);
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		printf("\nx0 : %f x_p : %f y0 : %f y_p : %f\n", vars->ray_x, vars->play_x, vars->ray_y, vars->play_y);
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y - vars->play_y, 2));
		// vars->ray_x = vars->play_x;
		// printf("distance : %f\n", distance);
		double h = calculate_wall_height(vars, distance, ray_angle);
		draw_wall(vars, x++, h);
		// printf("x : %d ", x);
		// printf("ray : %d %f\n", i, distance);
		// printf("Thales : %d\n", h);
		vars->angle += 0.05;
		while (vars->angle < 0)
			vars->angle += 360.0;
		while (vars->angle >= 360)
			vars->angle -= 360.0;
		i++;
	}
	vars->angle = angle + (y * 0.5);
	// printf("%f", vars->angle);
}
