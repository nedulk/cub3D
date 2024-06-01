/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:24:07 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 11:40:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_vars *vars)
{
	vars->angle -= 30;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle += 30;
}

void	move_backward(t_vars *vars)
{
	vars->angle -= 30;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x - vars->rotate_x1;
	vars->play_y = vars->play_y - vars->rotate_y1;
	if (check_walls(vars) == 1)
	{
		vars->play_x += vars->rotate_x1;
		vars->play_y += vars->rotate_y1;
	}
	vars->angle += 30;
}

void	move_right(t_vars *vars)
{
	vars->angle += 60;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle -= 60;
}

void	move_left(t_vars *vars)
{
	vars->angle -= 120;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle += 120;
}