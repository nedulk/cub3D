/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:30:38 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/10 12:32:50 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_menu(t_vars *vars)
{
	vars->loading = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading.xpm", &vars->width, &vars->height);
	vars->loading_1 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_1.xpm", &vars->width, &vars->height);
	vars->loading_2 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_2.xpm", &vars->width, &vars->height);
	vars->loading_3 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_3.xpm", &vars->width, &vars->height);
	vars->loading_sky = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_sky.xpm", &vars->width, &vars->height);
	vars->loading_360 = mlx_xpm_file_to_image(vars->mlx,
			"./img/loading_360.xpm", &vars->width, &vars->height);
	vars->play_click = mlx_xpm_file_to_image(vars->mlx,
			"./img/play.xpm", &vars->width, &vars->height);
	vars->play_selec = mlx_xpm_file_to_image(vars->mlx,
			"./img/play_selec.xpm", &vars->width, &vars->height);
	vars->title = mlx_xpm_file_to_image(vars->mlx,
			"./img/title.xpm", &vars->width, &vars->height);
}

void	game_textures(t_vars *vars)
{
	vars->texture_n = load_texture(vars, vars->texture[0]);
	vars->texture_s = load_texture(vars, vars->texture[1]);
	vars->texture_w = load_texture(vars, vars->texture[2]);
	vars->texture_e = load_texture(vars, vars->texture[3]);
	vars->texture_d = load_texture(vars, "./img/texture_d.xpm");
	if (SKY == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_sky,
			LOAD_X, LOAD_Y);
		vars->texture_sky = load_texture(vars, "./img/texture_sky.xpm");
	}
	if (SKY == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_360,
			LOAD_X, LOAD_Y);
		vars->texture_sky = load_texture(vars, "./img/texture_sky_360.xpm");
	}
}

void	sprites_sky_floor(t_vars *vars)
{
	vars->sprite = ft_calloc(5, sizeof(int **));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading,
		LOAD_X, LOAD_Y);
	vars->sprite[0] = load_texture(vars, "./img/sprite_11.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_1,
		LOAD_X, LOAD_Y);
	vars->sprite[1] = load_texture(vars, "./img/sprite_22.xpm");
	vars->sprite[2] = load_texture(vars, "./img/sprite_33.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_2,
		LOAD_X, LOAD_Y);
	vars->sprite[3] = load_texture(vars, "./img/sprite_44.xpm");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_3,
		LOAD_X, LOAD_Y);
	vars->sprite[4] = load_texture(vars, "./img/sprite_55.xpm");
}
