/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param_nsew.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:20:48 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/18 12:49:19 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	invalid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			printf(RED"Error\n"RESET);
			printf(YELLOW"Invalid character found\n"RESET);
			return (1);
		}
		i++;
	}
	return (0);
}

int	handle_texture_we(char *line, t_vars *vars)
{
	if (ft_strncmp(line, "WE ", 3) == 0 && vars->we == 0)
	{
		vars->we = 1;
		vars->pass = 1;
		vars->texture[2] = stock_path(line, 2);
		return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0 && vars->ea == 0)
	{
		vars->ea = 1;
		vars->pass = 1;
		vars->texture[3] = stock_path(line, 2);
		return (1);
	}
	return (0);
}

int	handle_texture(char *line, t_vars *vars)
{
	char	*temp;

	temp = line;
	while (*temp == ' ')
		temp++;
	if (ft_strncmp(temp, "NO ", 3) == 0 && vars->no == 0)
	{
		vars->no = 1;
		vars->pass = 1;
		vars->texture[0] = stock_path(temp, 2);
		return (1);
	}
	else if (ft_strncmp(temp, "SO ", 3) == 0 && vars->so == 0)
	{
		vars->so = 1;
		vars->pass = 1;
		vars->texture[1] = stock_path(temp, 2);
		return (1);
	}
	if (handle_texture_we(temp, vars) == 1)
		return (1);
	return (0);
}

int	handle_fc(char *line, t_vars *vars)
{
	char	*temp;

	temp = line;
	while (*temp == ' ')
		temp++;
	if (ft_strncmp(temp, "F ", 2) == 0 && vars->f == 0)
	{
		vars->f = 1;
		vars->pass = 1;
		vars->texture[4] = stock_path(temp, 1);
		return (1);
	}
	else if (ft_strncmp(temp, "C ", 2) == 0 && vars->c == 0)
	{
		vars->c = 1;
		vars->pass = 1;
		vars->texture[5] = stock_path(temp, 1);
		return (1);
	}
	return (0);
}

int	handle_map(char *line, t_vars *vars, int i, int fd)
{
	if (found_map(line) == 1)
	{
		if (vars->no == 1 && vars->so == 1 && vars->we == 1
			&& vars->ea == 1 && vars->f == 1 && vars->c == 1)
		{
			free(line);
			vars->line_map = i;
			return (0);
		}
		else
		{
			printf(RED"Error\n"RESET);
			printf(YELLOW"Missing parameter\n"RESET);
			free_line(line, fd);
			return (1);
		}
	}
	return (-1);
}
