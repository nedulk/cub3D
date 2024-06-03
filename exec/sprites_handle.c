/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:45:02 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/03 15:57:22 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_sprites(t_vars *vars)
{
	static int i = 0;
	int x;
	int y;
	int offset_x = 100;
	int offset_y = 100;
	
	y = 0;
	while (y < SPRITE_HEIGHT)
	{
		x = 0;
		while (x < SPRITE_WIDTH)
		{
			int color = vars->sprite[i][y][x];
			if (color != TRANSPARENT_COLOR)
				my_mlx_pixel_put(vars, x + offset_x, y + offset_y, color);
			x++;
		}
		y++;
	}
	if (i == 4)
		i = 0;
	else
		i++;
}