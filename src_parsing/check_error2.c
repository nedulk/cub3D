/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:55:38 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 17:33:20 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_nsew(t_vars *vars)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (vars->map[a] != NULL)
	{
		while (vars->map[a][i])
		{
			if (vars->map[a][i] == 'N' || vars->map[a][i] == 'S'
				|| vars->map[a][i] == 'W' || vars->map[a][i] == 'E')
				vars->e += 1;
			i++;
		}
		i = 0;
		a++;
	}
	if (vars->e == 1)
		return (0);
	printf(RED"Error\n" RESET);
	printf(YELLOW"Check numbers of: N S E W\n"RESET);
	return (1);
}

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
