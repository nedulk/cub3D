/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:29:24 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/11 17:42:00 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_double_int(int **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < RESOLUTION)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	free_triple_int(t_vars *vars)
{
	int	i;
	int	j;

	if (!vars->sprite)
		return ;
	i = 0;
	while (vars->sprite[i] && i < 5)
	{
		j = 0;
		while (j < SPRITE_HEIGHT)
		{
			free(vars->sprite[i][j]);
			vars->sprite[i][j] = NULL;
			j++;
		}
		free(vars->sprite[i]);
		vars->sprite[i] = NULL;
		i++;
	}
	free(vars->sprite);
	vars->sprite = NULL;
}

void	destroy_image2(t_vars *vars)
{
	if (vars->button_clicked == 1)
		mlx_destroy_image(vars->mlx, vars->img);
}

void	destroy_image(t_vars *vars)
{
	if (vars->play_click)
		mlx_destroy_image(vars->mlx, vars->play_click);
	if (vars->play_selec)
		mlx_destroy_image(vars->mlx, vars->play_selec);
	if (vars->title)
		mlx_destroy_image(vars->mlx, vars->title);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->celing)
		mlx_destroy_image(vars->mlx, vars->celing);
	if (vars->floor)
		mlx_destroy_image(vars->mlx, vars->floor);
	if (vars->loading)
		mlx_destroy_image(vars->mlx, vars->loading);
	if (vars->loading_1)
		mlx_destroy_image(vars->mlx, vars->loading_1);
	if (vars->loading_2)
		mlx_destroy_image(vars->mlx, vars->loading_2);
	if (vars->loading_3)
		mlx_destroy_image(vars->mlx, vars->loading_3);
	if (vars->loading_sky)
		mlx_destroy_image(vars->mlx, vars->loading_sky);
	if (vars->loading_360)
		mlx_destroy_image(vars->mlx, vars->loading_360);
	destroy_image2(vars);
}

void	ft_exit(t_vars *vars)
{
	destroy_image(vars);
	free_texture(vars->texture);
	free_double_char(vars->map);
	free_double_int(vars->texture_n);
	free_double_int(vars->texture_s);
	free_double_int(vars->texture_e);
	free_double_int(vars->texture_w);
	free_double_int(vars->texture_d);
	if (SKY == 1 || SKY == 2)
		free_double_int(vars->texture_sky);
	free_triple_int(vars);
	if (vars->mlx && vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
	close_fd();
	exit(0);
}
