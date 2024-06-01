/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:54:10 by dboire            #+#    #+#             */
/*   Updated: 2024/05/31 19:23:46 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_SO(t_vars *vars, double i, double y)
{
	int		test_xmap = vars->x_map;
	int		test_ymap = vars->y_map;

	if ((i - 0.01) < 0)
	{
		if ((y + 0.01 > 1))
		{
			if(vars->map[test_ymap -1][test_xmap] == '1' && vars->map[test_ymap][test_xmap + 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}
int	check_NE(t_vars *vars, double i, double y)
{
	int		test_xmap = vars->x_map;
	int		test_ymap = vars->y_map;

	if ((i + 0.01) > 1)
	{
		if ((y - 0.01 < 0))
		{
			if(vars->map[test_ymap + 1][test_xmap] == '1' && vars->map[test_ymap][test_xmap - 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}

int	check_NO(t_vars *vars, double i, double y)
{
	int		test_xmap = vars->x_map;
	int		test_ymap = vars->y_map;

	if ((i - 0.01) < 0)
	{
		if ((y - 0.01 < 0))
		{
			if(vars->map[test_ymap + 1][test_xmap] == '1' && vars->map[test_ymap][test_xmap + 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}


int	check_SE(t_vars *vars, double i, double y)
{
	int		test_xmap = vars->x_map;
	int		test_ymap = vars->y_map;

	if ((i + 0.01) >= 1)
	{
		if ((y + 0.01 >= 1))
		{
			if(vars->map[test_ymap - 1][test_xmap] == '1' && vars->map[test_ymap][test_xmap - 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}

double	calculate_i(t_vars *vars, double i)
{
	while(i < vars->ray_x)
	{
		i += EDGE;
		vars->x_map++;
	}
	i = (i - vars->ray_x) / EDGE;
	if(vars->x_map > 0)
		vars->x_map -= 1;
	return(i);
}

double	calculate_y(t_vars *vars, double y)
{
	while(y < vars->ray_y)
	{
		y += EDGE;
		vars->y_map++;
	}
	y = (y - vars->ray_y) / EDGE;
	if(vars->y_map > 0)
		vars->y_map -= 1;
	return (y);
}

int	check_walls_path(t_vars *vars)
{
	double	i;
	double	y;
	
	vars->x_map = 0;
	vars->y_map = 0;
	vars->diagonals = 0;
	i = 0;
	y = 0;
	i = calculate_i(vars, i);
	y = calculate_y(vars, y);
	if ((vars->incx < 0 && vars->incy < 0) && (vars->x_map > 0 && vars->y_map > 0))
		check_NO(vars, i, y);
	else if ((vars->incx > 0 && vars->incy < 0) && (vars->x_map > 0 && vars->y_map > 0))
		check_NE(vars, i, y);
	else if ((vars->incx < 0 && vars->incy > 0) && (vars->x_map > 0 && vars->y_map > 0))
		check_SO(vars, i, y);
	else if ((vars->incx > 0 && vars->incy > 0) && (vars->x_map > 0 && vars->y_map > 0))
		check_SE(vars, i, y);
	if(vars->map[vars->y_map][vars->x_map] == '1' || vars->diagonals == 1)
	{
		vars->wall_hit_x = vars->ray_x;
		vars->wall_hit_y = vars->ray_y;
		return (1);
	}
	return (0);
}

int	check_px_wall(t_vars *vars, float x, float y)
{
    int		x_map;
    int		y_map;
    
    x_map = (int)(x / EDGE);
    y_map = (int)(y / EDGE);
    if(vars->map[y_map][x_map] == '1')
        return (1);
    return (0);
}
int	check_walls_ray(t_vars *vars)
{
	double	i;
	double	y;
	
	vars->x_map = 0;
	vars->y_map = 0;
	i = 0;
	y = 0;
	i = calculate_i(vars, i);
	y = calculate_y(vars, y);
	vars->pos_x = i;
	vars->pos_y = y;
    if(vars->map[vars->y_map][vars->x_map] == '1')
    {
		if (vars->play_x < vars->wall_hit_x && check_px_wall(vars, vars->wall_hit_x - 1, vars->wall_hit_y) == 0)
			return (WEST);
		else if (vars->play_x > vars->wall_hit_x && check_px_wall(vars, vars->wall_hit_x + 1, vars->wall_hit_y) == 0)
			return (EAST);
		else if (vars->play_y < vars->wall_hit_y && check_px_wall(vars, vars->wall_hit_x, vars->wall_hit_y - 1) == 0)
			return (SOUTH);
		else if (vars->play_y > vars->wall_hit_y && check_px_wall(vars, vars->wall_hit_x, vars->wall_hit_y + 1) == 0)
			return (NORTH);
    }
    return (0);
}

double	calculate_play_i(t_vars *vars, double i)
{
	while(i < vars->play_x)
	{
		i += EDGE;
		vars->x_map++;
	}
	i = (i - vars->play_x) / EDGE;
	if(vars->x_map > 0)
		vars->x_map -= 1;
	return (i);
}

double	calculate_play_y(t_vars *vars, double y)
{
	while(y < vars->play_y)
	{
		y += EDGE;
		vars->y_map++;
	}
	y = (y - vars->play_y) / EDGE;
	if(vars->y_map > 0)
		vars->y_map -= 1;
	return (y);
	if(vars->y_map > 0)
		vars->y_map -= 1;
}

int	check_walls(t_vars *vars)
{
	double	i;
	double	y;
	
	vars->x_map = 0;
	vars->y_map = 0;
	i = 0;
	y = 0;
	i = calculate_play_i(vars, i);
	y = calculate_play_y(vars, y);
	if(vars->map[vars->y_map][vars->x_map] == '1')
		return (1);
	return (0);
}

void	draw_grid(t_vars *vars)
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
			else if(vars->map[i][y] == '0')
			{
				draw_floor_tile(vars);
				vars->y = vars->y0;
			}
			else if (vars->map[i][y] == ' ')
				vars->x += EDGE;
			if(vars->map[i][y] == 'N')
			{
				draw_player(vars);
				vars->map[i][y] = '0';
				vars->y = vars->y0;
				vars->x += EDGE;
			}
			y++;
		}
		vars->y += EDGE;
		i++;
	}
}
void move_forward(t_vars *vars, double speed)
{
	(void)speed;
	vars->angle -= 30;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if(check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle += 30;
}

void move_backward(t_vars *vars, double speed)
{
	(void)speed;
	vars->angle -= 30;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x - vars->rotate_x1;
	vars->play_y = vars->play_y - vars->rotate_y1;
	if(check_walls(vars) == 1)
	{
		vars->play_x += vars->rotate_x1;
		vars->play_y += vars->rotate_y1;
	}
	vars->angle += 30;
}

void move_right(t_vars *vars)
{
	vars->angle += 60;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if(check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle -= 60;
}

void move_left(t_vars *vars)
{
	vars->angle -= 120;
	vars->ray_x0 = vars->play_x;
	vars->ray_y0 = vars->play_y;
	rotation_matrix(vars);
	vars->play_x = vars->play_x + vars->rotate_x1;
	vars->play_y = vars->play_y + vars->rotate_y1;
	if(check_walls(vars) == 1)
	{
		vars->play_x -= vars->rotate_x1;
		vars->play_y -= vars->rotate_y1;
	}
	vars->angle += 120;
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
		vars->angle -= 4;
	if (keycode == XK_Right)
		vars->angle += 4;
	if (keycode == XK_w)
		move_forward(vars, 1.0);
	else if (keycode == XK_a)
		move_left(vars);
	else if (keycode == XK_s)
		move_backward(vars, 1.0);
	else if (keycode == XK_d)
		move_right(vars);
	else if (keycode == XK_Escape)
		exit(0);
	re_draw_img(vars);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)y;
	int delta;

	if(vars->first_x < x - 25 || vars->first_x > x + 25)
	{
		vars->last_x = vars->first_x;
		vars->first_x = x;
		delta = vars->first_x - vars->last_x;
		if (delta > 0 )
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
	vars->angle = 0; // rajouter if selon orientation
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