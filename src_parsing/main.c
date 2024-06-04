/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:52 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/04 16:11:54 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	load_img(t_vars *vars)
{
	///LOADING SCREEN
	vars->loading = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading.xpm", &vars->width, &vars->height);
	vars->loading_1 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_1.xpm", &vars->width, &vars->height);
	vars->loading_2 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_2.xpm", &vars->width, &vars->height);
	vars->loading_3 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_3.xpm", &vars->width, &vars->height);
	
	///MENU
	vars->play_click = mlx_xpm_file_to_image(vars->mlx,
			"./img/play.xpm", &vars->width, &vars->height);
	vars->play_selec = mlx_xpm_file_to_image(vars->mlx,
			"./img/play_selec.xpm", &vars->width, &vars->height);
	vars->title = mlx_xpm_file_to_image(vars->mlx,
			"./img/title.xpm", &vars->width, &vars->height);
	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->title,
		vars->title_x, vars->title_y);
	
	///GAME TEXTURES
	vars->texture_N = load_texture(vars, "./img/texture_N.xpm");
	vars->texture_W = load_texture(vars, "./img/texture_W.xpm");
	vars->texture_S = load_texture(vars, "./img/texture_S.xpm");
	vars->texture_E = load_texture(vars, "./img/texture_E.xpm");
	vars->texture_D = load_texture(vars, "./img/texture_D.xpm");
	vars->texture_C = load_texture(vars, "./img/texture_C.xpm");
	
	///SPRITES
	vars->sprite = ft_calloc(5, sizeof(int **));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading, LOAD_X, LOAD_Y);	
	vars->sprite[0] = load_texture(vars, "./img/sprite_11.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_1, LOAD_X, LOAD_Y);	
	vars->sprite[1] = load_texture(vars, "./img/sprite_22.xpm");
	vars->sprite[2] = load_texture(vars, "./img/sprite_33.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_2, LOAD_X, LOAD_Y);
	vars->sprite[3] = load_texture(vars, "./img/sprite_44.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_3, LOAD_X, LOAD_Y);
	vars->sprite[4] = load_texture(vars, "./img/sprite_55.xpm");
	
	///MINIMAP TEXTURES
	// vars->wall = create_img(vars->mlx, EDGE, 0x808080);
	
	///SKY AND FLOOR
	vars->celing = create_rectangle_img(vars->mlx, WIDTH, HEIGHT / 2, vars->celing_color);
	vars->floor = create_rectangle_img(vars->mlx, WIDTH, HEIGHT / 2, vars->floor_color);

	mlx_clear_window(vars->mlx, vars->win);
}

void	init_vars(t_vars *vars)
{
	vars->bool = 0;
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
	(void)argc;
	(void)argv;
	t_vars	*vars;
	
	vars = ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
	{
		printf("Error\nMalloc failure\n");
		return (0);
	}
	init_vars(vars);
	if (parsing(vars, argv, argc) == 1)
	{
		ft_exit(vars);
		return (1);
	}
	init_vars2(vars);
	vars->mlx = mlx_init();
	menu_player(vars);
	return (0);
}
