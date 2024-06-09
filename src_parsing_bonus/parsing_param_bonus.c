/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:19 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/08 17:49:40 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	found_map(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (1);
		return (0);
	}
	return (0);
}

char	*stock_path(char *line, int i)
{
	int		j;
	char	*texture;

	j = 0;
	line = remove_space(line);
	texture = ft_calloc(1, sizeof(char) * ft_strlen(line));
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		texture[j] = line[i];
		i++;
		j++;
	}
	texture[j] = '\0';
	free(line);
	line = NULL;
	return (texture);
}

int	setup_resources(char *map, t_vars *vars, int *fd)
{
	vars->texture = ft_calloc(1, sizeof(char *) * 7);
	if (vars->texture == NULL)
		return (handle_error("Can't upload texture\n"));
	vars->texture[6] = NULL;
	*fd = open(map, O_RDONLY);
	if (*fd == -1)
		return (handle_error("Can't open map\n"));
	return (0);
}

int	process_lines(int fd, t_vars *vars)
{
	static int	i = 0;
	char		*line;
	int			result;

	line = NULL;
	while (line || i == 0)
	{
		vars->pass = 0;
		line = get_next_line(fd);
		handle_texture(line, vars);
		handle_fc(line, vars);
		if (vars->pass == 0 && found_map(line) == 0 && line[0] != ' '
			&& line[0] != '\0' && line[0] != '\n' && line[0] != '\t')
			return (free_line(line, fd));
		result = handle_map(line, vars, i, fd);
		if (result != -1)
			return (result);
		free(line);
		i++;
	}
	return (handle_error("Missing map\n"));
}

int	check_param(char *map, t_vars *vars)
{
	int	fd;
	int	result;

	result = setup_resources(map, vars, &fd);
	if (result != 0)
		return (result);
	return (process_lines(fd, vars));
}
