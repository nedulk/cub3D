/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:54:10 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 18:24:41 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_px_wall(t_vars *vars, float x, float y)
{
	int	x_map;
	int	y_map;

	x_map = (int)(x / EDGE);
	y_map = (int)(y / EDGE);
	if (vars->map[y_map][x_map] == '1')
		return (1);
	return (0);
}

void	re_draw_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	redraw_grid(vars);
	redraw_grid_wo_p(vars);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == XK_Left)
		vars->angle -= 2;
	if (keycode == XK_Right)
		vars->angle += 2;
	if (keycode == XK_w)
		move_forward(vars);
	else if (keycode == XK_a)
		move_left(vars);
	else if (keycode == XK_s)
		move_backward(vars);
	else if (keycode == XK_d)
		move_right(vars);
	re_draw_img(vars);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	int	delta;

	(void)y;
	if (vars->first_x < x - 25 || vars->first_x > x + 25)
	{
		vars->last_x = vars->first_x;
		vars->first_x = x;
		delta = vars->first_x - vars->last_x;
		if (delta > 0)
			vars->angle += delta / 2;
		else if (delta < 0)
		{
			delta = -delta;
			vars->angle -= delta / 2;
		}
		re_draw_img(vars);
	}
	return (0);
}

int	exec(t_vars *vars)
{
	vars->angle = 0;
	vars->y = 0;
	vars->first_x = 0;
	vars->last_x = 0;
	vars->y0 = vars->y;
	vars->x_map = 0;
	vars->y_map = 0;
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	draw_grid(vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, move, vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, mouse_move, vars);
	mlx_loop(vars->mlx);
	return (0);
}
