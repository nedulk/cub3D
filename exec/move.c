/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:03:39 by dboire            #+#    #+#             */
/*   Updated: 2024/06/11 16:51:47 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
