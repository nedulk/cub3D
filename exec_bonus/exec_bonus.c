/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:54:10 by dboire            #+#    #+#             */
/*   Updated: 2024/06/11 16:31:38 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_px_wall(t_vars *vars, float x, float y)
{
	int	x_map;
	int	y_map;

	x_map = (int)(x / EDGE);
	y_map = (int)(y / EDGE);
	if (vars->map[y_map][x_map] == '1' || vars->map[y_map][x_map] == 'D')
		return (1);
	return (0);
}

void	re_draw_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	redraw_grid(vars);
	redraw_grid_wo_p(vars);
	draw_sprites(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == XK_Left)
		vars->angle -= 2;
	else if (keycode == XK_Right)
		vars->angle += 2;
	else if (keycode == XK_w)
		vars->moving_forward = 1;
	else if (keycode == XK_a)
		vars->moving_left = 1;
	else if (keycode == XK_s)
		vars->moving_backward = 1;
	else if (keycode == XK_d)
		vars->moving_right = 1;
	else if (keycode == XK_e)
		open_door(vars);
	else if (keycode == XK_Tab)
		vars->map_press = 1;
	else if (keycode == XK_Escape)
		ft_exit(vars);
	return (0);
}

int	update_player_position(t_vars *vars)
{
	int	delta;

	delta = vars->first_x - vars->last_x;
	if (delta > 0)
		vars->angle += delta / 2;
	else if (delta < 0)
	{
		delta = -delta;
		vars->angle -= delta / 2;
	}
	if (vars->moving_forward)
		move_forward(vars);
	if (vars->moving_backward)
		move_backward(vars);
	if (vars->moving_left)
		move_left(vars);
	if (vars->moving_right)
		move_right(vars);
	re_draw_img(vars);
	return (0);
}

int	exec(t_vars *vars)
{
	int	x;
	int	y;

	vars->x_map = 1;
	vars->y_map = 1;
	vars->y = 0;
	vars->y0 = vars->y;
	vars->x_map = 0;
	vars->y_map = 0;
	vars->prev_pos_x = 1;
	vars->prev_pos_y = 1;
	mlx_clear_window(vars->mlx, vars->win);
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	draw_grid(vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, move, vars);
	mlx_hook(vars->win, KeyRelease, KeyReleaseMask, stop_move, vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, mouse_move, vars);
	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	mlx_loop_hook(vars->mlx, update_player_position, vars);
	mlx_mouse_hide(vars->mlx, vars->win);
	mlx_loop(vars->mlx);
	return (0);
}
