/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:24:07 by dboire            #+#    #+#             */
/*   Updated: 2024/06/08 11:57:05 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_vars *vars)
{
	vars->angle -= FOV / 2;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls_player(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	else
	{
		vars->prev_pos_x = vars->x_map;
		vars->prev_pos_y = vars->y_map;
	}
	printf("vars->x_map : %d\n", vars->x_map);
	printf("vars->y_map : %d\n", vars->y_map);
	printf("vars->prev_pos_x : %d\n", vars->prev_pos_x);
	printf("vars->prev_pos_y : %d\n", vars->prev_pos_y);
	printf("prev_pos map : %c\n", vars->map[vars->prev_pos_y][vars->prev_pos_x]);
	printf("\n");
	vars->angle += FOV / 2;
}

void	move_backward(t_vars *vars)
{
	vars->angle -= FOV / 2;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x - vars->rotate_x1;
	vars->play_y = vars->play_y - vars->rotate_y1;
	if (check_walls_player(vars) == 1)
	{
		vars->play_x += vars->rotate_x1;
		vars->play_y += vars->rotate_y1;
	}
	else
	{
		vars->prev_pos_x = vars->x_map;
		vars->prev_pos_y = vars->y_map;
	}
	printf("vars->x_map : %d\n", vars->x_map);
	printf("vars->y_map : %d\n", vars->y_map);
	printf("vars->prev_pos_x : %d\n", vars->prev_pos_x);
	printf("vars->prev_pos_y : %d\n", vars->prev_pos_y);
	printf("prev_pos map : %c\n", vars->map[vars->prev_pos_y][vars->prev_pos_x]);
	printf("\n");
	vars->angle += FOV / 2;
}

void	move_right(t_vars *vars)
{
	vars->angle += FOV - (FOV / 3);
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls_player(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	else
	{
		vars->prev_pos_x = vars->x_map;
		vars->prev_pos_y = vars->y_map;
	}
	printf("vars->x_map : %d\n", vars->x_map);
	printf("vars->y_map : %d\n", vars->y_map);
	printf("vars->prev_pos_x : %d\n", vars->prev_pos_x);
	printf("vars->prev_pos_y : %d\n", vars->prev_pos_y);
	printf("prev_pos map : %c\n", vars->map[vars->prev_pos_y][vars->prev_pos_x]);
	printf("\n");
	vars->angle -= FOV - (FOV / 3);
}

void	move_left(t_vars *vars)
{
	vars->angle -= FOV + (FOV / 3);
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if (check_walls_player(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	else
	{
		vars->prev_pos_x = vars->x_map;
		vars->prev_pos_y = vars->y_map;
	}
	printf("vars->x_map : %d\n", vars->x_map);
	printf("vars->y_map : %d\n", vars->y_map);
	printf("vars->prev_pos_x : %d\n", vars->prev_pos_x);
	printf("vars->prev_pos_y : %d\n", vars->prev_pos_y);
	printf("prev_pos map : %c\n", vars->map[vars->prev_pos_y][vars->prev_pos_x]);
	printf("\n");
	vars->angle += FOV + (FOV / 3);
}
