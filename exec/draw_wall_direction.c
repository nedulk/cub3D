/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:54:06 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 12:23:59 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_north_wall(t_vars *vars, double distance_to_wall, int x)
{
	int		line_height;
	int		j;
	int		po;
	int		tex_y;
	double	proportion;
	int		tex_start;
	int		tex_end;

	line_height = vars->draw_end - vars->draw_start;
	j = vars->draw_start;
	while (j < vars->draw_end)
	{
		if (distance_to_wall <= 40)
		{
			proportion = distance_to_wall / 40;
			tex_start = (RESOLUTION - RESOLUTION * proportion) / 2;
			tex_end = RESOLUTION - tex_start;
			tex_y = tex_start + ((j - vars->draw_start) * (tex_end - tex_start))
				/ line_height;
		}
		else
			tex_y = ((j - vars->draw_start) * RESOLUTION) / line_height;
		po = vars->pos_x * RESOLUTION;
		my_mlx_pixel_put(vars, x, j, vars->texture_N[tex_y][po]);
		j++;
	}
}

void	draw_south_wall(t_vars *vars, double distance_to_wall, int x)
{
	int		line_height;
	int		j;
	int		po;
	int		tex_y;
	double	proportion;
	int		tex_start;
	int		tex_end;

	j = vars->draw_start;
	line_height = vars->draw_end - vars->draw_start;
	while (j < vars->draw_end)
	{
		if (distance_to_wall <= 40)
		{
			proportion = distance_to_wall / 40;
			tex_start = (RESOLUTION - RESOLUTION * proportion) / 2;
			tex_end = RESOLUTION - tex_start;
			tex_y = tex_start + ((j - vars->draw_start) * (tex_end - tex_start))
				/ line_height;
		}
		else
			tex_y = ((j - vars->draw_start) * RESOLUTION) / line_height;
		po = vars->pos_x * RESOLUTION;
		my_mlx_pixel_put(vars, x, j, vars->texture_S[tex_y][po]);
		j++;
	}
}

void	draw_east_wall(t_vars *vars, double distance_to_wall, int x)
{
	int		line_height;
	int		j;
	int		po;
	int		tex_y;
	double	proportion;
	int		tex_start;
	int		tex_end;

	j = vars->draw_start;
	line_height = vars->draw_end - vars->draw_start;
	while (j < vars->draw_end)
	{
		if (distance_to_wall <= 40)
		{
			proportion = distance_to_wall / 40;
			tex_start = (RESOLUTION - RESOLUTION * proportion) / 2;
			tex_end = RESOLUTION - tex_start;
			tex_y = tex_start + ((j - vars->draw_start) * (tex_end - tex_start))
				/ line_height;
		}
		else
			tex_y = ((j - vars->draw_start) * RESOLUTION) / line_height;
		po = vars->pos_y * RESOLUTION;
		my_mlx_pixel_put(vars, x, j, vars->texture_E[tex_y][po]);
		j++;
	}
}

void	draw_west_wall(t_vars *vars, double distance_to_wall, int x)
{
	int line_height;
	int j;
	int po;
	int tex_y;

	j = vars->draw_start;
	line_height = vars->draw_end - vars->draw_start;
	while (j < vars->draw_end)
	{
		if (distance_to_wall <= 40)
		{
			double proportion = distance_to_wall / 40;
			int tex_start = (RESOLUTION - RESOLUTION * proportion) / 2;
			int tex_end = RESOLUTION - tex_start;
			tex_y = tex_start + ((j - vars->draw_start) * (tex_end - tex_start))
				/ line_height;
		}
		else
			tex_y = ((j - vars->draw_start) * RESOLUTION) / line_height;
		po = vars->pos_y * RESOLUTION;
		my_mlx_pixel_put(vars, x, j, vars->texture_W[tex_y][po]);
		j++;
	}
}
