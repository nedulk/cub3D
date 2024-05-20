/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:44 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 17:24:14 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	redraw_player(t_vars *vars)
{
	int	i;
	
	i = 2;
	if(check_walls(vars) == 1)
		return ;
	if(check_walls2(vars) == 1)
		return ;
	if(vars->angle == -1)
		vars->angle = 359;
	vars->angle =  vars->angle % 360;
	// printf("%d", vars->angle);
	my_mlx_pixel_put(vars, vars->play_x, vars->play_y, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x + 1, vars->play_y, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x, vars->play_y + 1, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x + 1, vars->play_y + 1, 0x00FF0000);
	draw_rays(vars);
}

void	redraw_grid(t_vars *vars)
{
	int	i;
	int	y;
	
	i = 0;
	while (vars->map[i])
	{
		y = 0;
		vars->x = 0;
		vars->y0 = vars->y;
		while (vars->map[i][y])
		{
			if (vars->map[i][y] == '1')
				draw_wall_tile(vars);
			else if(vars->map[i][y] != '1')
			{
				draw_floor_tile(vars);
				vars->y = vars->y0;
			}
			y++;
		}
		vars->y = vars->y + EDGE;
		i++;
	}
	redraw_player(vars);
}