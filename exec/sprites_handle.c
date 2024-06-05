/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:45:02 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/05 11:44:13 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	counter_i(int *i, int *counter)
{
	if (*counter % 2 == 0)
	{
		if (*i == 4)
			*i = 0;
		else
			(*i)++;
	}
	return (*i);
}

void	draw_sprites_handle1(t_vars *vars, int *i, int *counter)
{
	int y;
	int	x;
	int	color;
	int offset_x;
	int offset_y;

	y = 0;
	x = 0;
	offset_x = 300;
	offset_y = 700;
	while (y < SPRITE_HEIGHT)
	{
		x = 0;
		while (x < SPRITE_WIDTH)
		{
			color = vars->sprite[*i][y][x];
			if (color != TRANSPARENT_COLOR)
				my_mlx_pixel_put(vars, x + offset_x, y + offset_y, color);
			x++;
		}
		y++;
	}
	*i = counter_i(i, counter);
	(*counter)++;
}

void	draw_sprites_handle2(t_vars *vars)
{
	int y;
	int	x;
	int	color;
	int offset_x;
	int offset_y;

	y = 0;
	x = 0;
	offset_x = 300;
	offset_y = 700;
	while (y < SPRITE_HEIGHT)
	{
		x = 0;
		while (x < SPRITE_WIDTH)
		{
			color = vars->sprite[0][y][x];
			if (color != TRANSPARENT_COLOR)
				my_mlx_pixel_put(vars, x + offset_x, y + offset_y, color);
			x++;
		}
		y++;
	}
}

void draw_sprites(t_vars *vars)
{
	static int counter = 0;
	static int	i = 0;

	if (vars->moving_forward == 1 || vars->moving_backward == 1 
		|| vars->moving_left == 1 || vars->moving_right == 1)
		draw_sprites_handle1(vars, &i, &counter);
	else 
		draw_sprites_handle2(vars);
}

void draw_sky_simple(t_vars *vars)
{
    int x;
    int y;
    int offset_x = 0;
    int offset_y = 0;
    
    y = 0;
    while (y < 540)
    {
        x = 0;
        while (x < 1920)
        {
            int texture_x = (x + offset_x) % 1920;
            int color = vars->texture_Sky[y][texture_x];
            my_mlx_pixel_put(vars, x, y + offset_y, color);
            x++;
        }
        y++;
    }
}

void draw_sky_img(t_vars *vars, double angle)
{
    int x;
    int y;
    int offset_x = (angle / 360) * 7680;
    int offset_y = 0;
    
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
            int texture_x = (x + offset_x) % 7680;
            int color = vars->texture_Sky[y][texture_x];
            my_mlx_pixel_put(vars, x, y + offset_y, color);
            x++;
        }
        y++;
    }
}

