/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:52 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/10 16:51:49 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_img(t_vars *vars)
{
	load_menu(vars);
	if (vars->title == NULL || vars->loading == NULL || vars->loading_1 == NULL
		|| vars->loading_2 == NULL || vars->loading_3 == NULL
		|| vars->loading_sky == NULL || vars->loading_360 == NULL
		|| vars->play_click == NULL || vars->play_selec == NULL)
	{
		printf(RED"Error\nLoading menu textures failed\n"RESET);
		ft_exit(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->title,
		vars->title_x, vars->title_y);
	game_textures(vars);
	sprites_sky_floor(vars);
	mlx_clear_window(vars->mlx, vars->win);
}

void	init_vars(t_vars *vars)
{
	vars->line = NULL;
	vars->button_clicked = 0;
	vars->width = 0;
	vars->height = 0;
	vars->map = NULL;
}

void	init_vars2(t_vars *vars)
{
	vars->play_button_x = (1920 / 2) - 64;
	vars->play_button_y = 500;
	vars->title_x = (1920 / 2) - 380;
	vars->title_y = 300;
}

int	menu_player(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT,
			"cub3D");
	load_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_click,
		vars->play_button_x, vars->play_button_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->title,
		vars->title_x, vars->title_y);
	event_game(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	(void)argc;
	(void)argv;
	vars = ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
	{
		printf("Error\nMalloc failure\n");
		return (0);
	}
	init_vars(vars);
	if (parsing(vars, argv, argc) == 1)
		ft_exit(vars);
	init_vars2(vars);
	vars->mlx = mlx_init();
	menu_player(vars);
	return (0);
}
