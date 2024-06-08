/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:03:39 by dboire            #+#    #+#             */
/*   Updated: 2024/06/08 15:07:02 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)y;
	vars->last_x = vars->first_x;
	vars->first_x = x;
	mlx_mouse_move(vars->mlx, vars->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	stop_move(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		vars->moving_forward = 0;
	else if (keycode == XK_a)
		vars->moving_left = 0;
	else if (keycode == XK_s)
		vars->moving_backward = 0;
	else if (keycode == XK_d)
		vars->moving_right = 0;
	else if (keycode == XK_Tab)
		vars->map_press = 0;
	return (0);
}