/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:32:19 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/18 11:47:55 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	nb_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (line || i == 0)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	return (i);
}

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

void	free_texture(char **texture)
{
	int	i;

	if (!texture)
		return ;
	i = 0;
	while (i < 6)
	{
		free(texture[i]);
		texture[i] = NULL;
		i++;
	}
	free(texture);
}

int	handle_error(char *message)
{
	printf(RED"Error\n"RESET);
	printf(YELLOW"%s"RESET, message);
	return (1);
}

int	free_line(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
