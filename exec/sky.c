/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:27:10 by dboire            #+#    #+#             */
/*   Updated: 2024/06/08 17:27:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sky_simple(t_vars *vars)
{
	int	x;
	int	y;
	int	texture_x;
	int	color;

	y = 0;
	while (y < 540)
	{
		x = 0;
		while (x < 1920)
		{
			texture_x = (x + 0) % 1920;
			color = vars->texture_sky[y][texture_x];
			my_mlx_pixel_put(vars, x, y + 0, color);
			x++;
		}
		y++;
	}
}

void	draw_sky_img(t_vars *vars, double angle)
{
	int	x;
	int	y;
	int	offset_x;
	int	texture_x;
	int	color;

	offset_x = (angle / 360) * 7680;
	y = 0;
	if (SKY == 1)
	{
		draw_sky_simple(vars);
		return ;
	}
	while (y < 540)
	{
		x = 0;
		while (x < 7680)
		{
			texture_x = (x + offset_x) % 7680;
			color = vars->texture_sky[y][texture_x];
			my_mlx_pixel_put(vars, x, y + 0, color);
			x++;
		}
		y++;
	}
}
