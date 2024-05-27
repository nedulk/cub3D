/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/27 11:41:47 by dboire           ###   ########.fr       */
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
    int wall_height;
	(void)vars;
	
    double corrected_distance = distance * cos(((ray_angle * (PI / 180.0)) - (vars->angle * (PI / 180.0))) * PI / 180.0);
    wall_height = (HEIGHT / corrected_distance) * 5;
    // pas plus grand que la hauteur de l'écran
    if (wall_height > HEIGHT)
        wall_height = HEIGHT;
    return (wall_height);
}
void draw_wall(t_vars *vars, int x, int wall_height)
{
	// int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	int draw_start = centerY - wall_height;	
	if(draw_start < 0)
		draw_start = 0;
	int draw_end = centerY + wall_height;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	// int wall_color = 0x330066;
	int j = draw_start;
	int tex_height = 64; // la hauteur de la texture
	int line_height = draw_end - draw_start; // la hauteur du mur à l'écran

	while (j < draw_end)
	{
		int tex_y = ((j - draw_start) * tex_height) / line_height;

		my_mlx_pixel_put(vars, x, j, vars->texture_w[tex_y % 64][x % 64]);
		j++;
	}
	while (j <= HEIGHT)
	{
		my_mlx_pixel_put(vars, x, j, vars->floor_color); // link avec parsing
		j++;
	}
	j = draw_start;
	while (j >= 0)
	{
		my_mlx_pixel_put(vars, x, j, vars->celing_color); // link avec parsing
		j--;
	}
	}

void	draw_rays(t_vars *vars)
{
	double	angle;
	double	distance;
	int	y;
	int	rays_number = 100;
	int x = 0;

	y = 1919;
	angle = vars->angle;
	vars->angle -= (FOV * PI / 180) / 2;
	while(x < y)
	{
		double ray_angle = vars->angle;
		vars->ray_x0 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		vars->ray_y = vars->ray_y0;
		vars->ray_x = vars->ray_x0;
		vars->ray_x1 = cos(vars->angle * PI / 180);
		vars->ray_y1 = sin(vars->angle * PI / 180);
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y - vars->play_y, 2));
		int h = calculate_wall_height(vars, distance, ray_angle);
		int column_start = (x * WIDTH) / rays_number;
        int column_end = ((x + 1) * WIDTH) / rays_number;
        int i = column_start;
        while(i < column_end)
        {
			draw_wall(vars, x, h);
			i++;
			x++;
		}
		vars->angle += (FOV * PI / 180) / rays_number;
		if (vars->angle < 0)
			vars->angle += 360.0;
		if (vars->angle >= 360)
			vars->angle -= 360.0;
	}
	vars->angle = angle;
}
