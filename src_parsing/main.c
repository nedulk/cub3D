/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:52 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/24 17:51:09 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_img(t_vars *vars)
{
	///MENU
	vars->play_click = mlx_xpm_file_to_image(vars->mlx,
			"./img/play.xpm", &vars->width, &vars->height);
	vars->play_selec = mlx_xpm_file_to_image(vars->mlx,
			"./img/play_selec.xpm", &vars->width, &vars->height);
	vars->title = mlx_xpm_file_to_image(vars->mlx,
			"./img/title.xpm", &vars->width, &vars->height);
	vars->you_win = mlx_xpm_file_to_image(vars->mlx,
			"./img/win.xpm", &vars->width, &vars->height);
	
	///GAME TEXTURES
	void	*img;
	char	*img_data;
	int		y;
	int		x;
	int		width;
	int		height;
	int		bits_per_pixel = 32;
	int 	endian = 1;
	int		size_line = 128 * (32 / 8);
	int		index;
	
	img = mlx_xpm_file_to_image(vars->mlx,
			"./img/texture.xpm", &width, &height);
	
	img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	
	vars->texture_w = malloc(height * sizeof(int*));
	y = 0;
	while(y < height)
	{
		vars->texture_w[y] = malloc(width * sizeof(int));
		y++;
	}
	y = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			index = (y * size_line + x * (bits_per_pixel / 8));
			vars->texture_w[y][x] = *(int*)(img_data + index);
			x++;
		}
		y++;
	}
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
	
	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		ft_printf("Error\nMalloc failure\n");
		return (0);
	}
	init_vars(vars);
	if (parsing(vars, argv, argc) == 1)
	{
		return (1);
	}
	init_vars2(vars);
	vars->mlx = mlx_init();
	load_img(vars);
	menu_player(vars);
	return (0);
}
