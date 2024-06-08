/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:31:34 by dboire            #+#    #+#             */
/*   Updated: 2024/06/08 17:32:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_correct_angle(t_vars *vars)
{
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
}

void	define_fov(t_vars *vars)
{
	vars->draw = 0;
	vars->rays_number = 1920;
	vars->angle_step = FOV / vars->rays_number;
	vars->angle -= FOV;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
}
