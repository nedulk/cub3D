/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 17:44:34 by kprigent         ###   ########.fr       */
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

int calculate_wall_height(int distance)
{
    int wall_height;

    wall_height = (HEIGHT / distance);
    // pas plus grand que la hauteur de l'écran
    if (wall_height > HEIGHT)
        wall_height = HEIGHT;
    return (wall_height);
}
void draw_wall(t_vars *vars, int x, int wall_height)
{
    // int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    

    int draw_start = centerY - wall_height / 2;
    if(draw_start < 0)
        draw_start = 0;
    int draw_end = centerY + wall_height / 2;
    if(draw_end >= HEIGHT)
        draw_end = HEIGHT;

    int wall_color = 0xFFFFFF;

    int j = draw_start;
    while (j < draw_end)
    {
        my_mlx_pixel_put(vars, x, j, wall_color);
        j++;
    }
}
void	draw_rays(t_vars *vars)
{
	int	i;
	float	angle;
	double	distance;
	int	y;

	y = 90;
	i = 0;
	angle = vars->angle - (y / 2);
	while(i < y)
	{
		vars->ray_x0 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		vars->ray_x1 = cos(vars->angle * PI / 180);
		vars->ray_y1 = sin(vars->angle * PI / 180);
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		distance = sqrt(pow(vars->ray_x0 - vars->play_x, 2) + pow(vars->ray_y0 - vars->play_y, 2));
		int h = calculate_wall_height(distance);
		draw_wall(vars, h, i);
		// printf("ray : %d %f\n", i, distance);
		// printf("Thales : %d\n", h);
		vars->angle += 1;
		vars->angle =  vars->angle % 360;
		i++;
	}
	vars->angle = angle + (y * 0.5);
}
