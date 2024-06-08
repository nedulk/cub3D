/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:28:47 by dboire            #+#    #+#             */
/*   Updated: 2024/06/08 17:29:17 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_door(t_vars *vars)
{
	if (vars->direction == DOOR_X)
		return (vars->pos_x * RESOLUTION);
	else
		return (vars->pos_y * RESOLUTION);
}

int	draw_door(t_vars *vars, double distance_to_wall, int x, int j)
{
	int	line_height;
	int	po;
	int	tex_y;
	int	tex_start;

	j = vars->draw_start;
	if (x == vars->last_xwall && j == vars->last_j)
		return (0);
	line_height = vars->draw_end - vars->draw_start;
	while (j < vars->draw_end)
	{
		if (distance_to_wall <= 40)
		{
			tex_start = (RESOLUTION - RESOLUTION * (distance_to_wall / 40)) / 2;
			tex_y = tex_start + ((j - vars->draw_start) * ((RESOLUTION
							- tex_start) - tex_start)) / line_height;
		}
		else
			tex_y = ((j - vars->draw_start) * RESOLUTION) / line_height;
		po = is_door(vars);
		my_mlx_pixel_put(vars, x, j, vars->texture_d[tex_y][po]);
		j++;
	}
	return (j);
}
