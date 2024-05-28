/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:57:47 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/28 19:19:21 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void draw_wall(t_vars *vars, int x, int wall_height)
{
	int centerY = HEIGHT / 2;

	int draw_start = centerY - wall_height;	
	if(draw_start < 0)
		draw_start = 0;
	int draw_end = centerY + wall_height;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	int j = draw_start;
	int tex_height = 128; // la hauteur de la texture
	int line_height = draw_end - draw_start; // la hauteur du mur à l'écran

	int direction = check_walls_ray(vars);
	if (direction == NORTH)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_N[tex_y][po]);
			j++;
		}
	}
	if (direction == EAST)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_E[tex_y][po]);
			j++;
		}
	}
	if (direction == SOUTH)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_S[tex_y][po]);
			j++;
		}
	}
	if (direction == WEST)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_W[tex_y][po]);
			j++;
		}
	}
	while (j <= HEIGHT)
	{
		my_mlx_pixel_put(vars, x, j, vars->floor_color);
		j++;
	}
	j = draw_start;
	while (j >= 0)
	{
		my_mlx_pixel_put(vars, x, j, vars->celing_color);
		j--;
	}
}