/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:29:24 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:44 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_double_char(char **tab)
{
    int	i;

    if (!tab)
        return ;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        tab[i] = NULL;
        i++;
    }
    free(tab);
}

void free_double_int(int **tab)
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

void free_triple_int(int ***tab)
{
	int	i;
	int	j;

	if (!tab)
		return ;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < SPRITE_HEIGHT)
		{
			free(tab[i][j]);
			tab[i][j] = NULL;
			j++;
		}
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
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
}


void	ft_exit(t_vars *vars)
{	
	destroy_image(vars);
	free_double_char(vars->texture);
	free_double_char(vars->map);
	free_double_int(vars->texture_N);
	free_double_int(vars->texture_S);
	free_double_int(vars->texture_E);
	free_double_int(vars->texture_W);
	free_double_int(vars->texture_D);
	free_triple_int(vars->sprite);
	if (vars->mlx && vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
	exit(0);
}

void	free_modified_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->l)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}
