/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:14:21 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/10 14:25:56 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_size_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (j > 46)
			return (1);
		i++;
	}
	if (i > 26)
		return (1);
	return (0);
}

int	convert_color_string_to_int(t_vars *vars, char *color_string)
{
	int		i;
	int		red;
	int		green;
	int		blue;
	char	**rgb_values;

	i = 0;
	rgb_values = ft_split(color_string, ',');
	red = ft_atoi(rgb_values[0]);
	green = ft_atoi(rgb_values[1]);
	blue = ft_atoi(rgb_values[2]);
	while (i < 3)
	{
		free(rgb_values[i]);
		i++;
	}
	free(rgb_values);
	vars->color_img = (red << 16) | (green << 8) | blue;
	return (vars->color_img);
}

int	parsing(t_vars *vars, char **argv, int argc)
{
	if (argc > 2)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Too much arguments\n"RESET);
		return (1);
	}
	else if (argc == 1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Please specify a map\n"RESET);
		return (1);
	}
	else if (check_param(argv[1], vars) == 1)
		return (1);
	else if ((vars->line_map != 0) && check_map(argv[1], vars) == 1)
		return (1);
	else if (check_param_valid(vars) == 1)
		return (1);
	vars->floor_color = convert_color_string_to_int(vars, vars->texture[4]);
	vars->celing_color = convert_color_string_to_int(vars, vars->texture[5]);
	return (0);
}
