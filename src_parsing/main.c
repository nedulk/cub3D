/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:52 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 12:53:08 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_img(t_vars *vars)
{
	vars->play_click = mlx_xpm_file_to_image(vars->mlx,
			"./img/play.xpm", &vars->width, &vars->height);
	vars->play_selec = mlx_xpm_file_to_image(vars->mlx,
			"./img/play_selec.xpm", &vars->width, &vars->height);
	vars->title = mlx_xpm_file_to_image(vars->mlx,
			"./img/title.xpm", &vars->width, &vars->height);
	vars->you_win = mlx_xpm_file_to_image(vars->mlx,
			"./img/win.xpm", &vars->width, &vars->height);
}

void	init_vars(t_vars *vars)
{
	vars->victory = 0;
	vars->start = 0;
	vars->line = NULL;
	vars->button_clicked = 0;
	vars->l = 0;
	vars->ll = 0;
	vars->e = 0;
	vars->p = 0;
	vars->c = 0;
	vars->wrong = 0;
	vars->width = 0;
	vars->height = 0;
	vars->map = NULL;
}

void	init_vars2(t_vars *vars)
{
	vars->play_x = (vars->ll * 64 / 2) - (40);
	vars->play_y = (vars->l * 64 / 2) + (32);
	vars->title_x = (vars->ll * 64 / 2) - 400;
	vars->title_y = (vars->l * 64 / 2) - (250);
}

int	menu_player(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->ll * 64, vars->l * 64,
			"cub3D");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_click,
		vars->play_x, vars->play_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->title,
		vars->title_x, vars->title_y);
	event_game(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		ft_printf("Error\nMalloc failure\n");
		return (0);
	}
	init_vars(vars);
	if (argc != 2 || check_error(argv[1], vars) == 0)
	{
		ft_printf("Error\nPlease specify a valid map\n");
		free_map(vars);
	}
	init_vars2(vars);
	vars->mlx = mlx_init();
	load_img(vars);
	menu_player(vars);
	return (0);
}
