/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:14:21 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/18 11:08:48 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	close_fd(void)
{
	int	i;

	i = 3;
	while (i <= 1023)
	{
		close(i);
		i++;
	}
}

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
	if (rgb_values[0] && rgb_values[1] && rgb_values[2] && !rgb_values[3])
	{
		red = ft_atoi(rgb_values[0]);
		green = ft_atoi(rgb_values[1]);
		blue = ft_atoi(rgb_values[2]);
		free_double_char(rgb_values);
		vars->color_img = (red << 16) | (green << 8) | blue;
		return (vars->color_img);
	}
	free_double_char(rgb_values);
	printf(RED"Error\nCheck F/C\n"RESET);
	return (-3);
}

int	check_format(char **argv)
{
	if (ft_strncmp (argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		printf(RED"Error\nPlease specify a .cub file\n"RESET);
		return (1);
	}
	return (0);
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
	if (check_format(argv) == 1)
		return (1);
	else if (check_param(argv[1], vars) == 1)
		return (1);
	else if ((vars->line_map != 0) && check_map(argv[1], vars) == 1)
		return (1);
	else if (check_param_valid(vars) == 1)
		return (1);
	vars->floor_color = convert_color_string_to_int(vars, vars->texture[4]);
	vars->celing_color = convert_color_string_to_int(vars, vars->texture[5]);
	if (vars->floor_color == -3 || vars->celing_color == -3)
		return (1);
	return (0);
}
