/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_chart.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:18:30 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/10 17:28:21 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	skip_lines(t_vars *vars, int fd, int *b)
{
	while (*b < vars->line_map)
	{
		vars->line = get_next_line(fd);
		free(vars->line);
		(*b)++;
	}
}

void	copy_line_to_map(t_vars *vars, int *a, int *i)
{
	while (vars->line[*i])
	{
		vars->map[*a][*i] = vars->line[*i];
		(*i)++;
	}
	vars->map[*a][*i] = '\0';
	*i = 0;
	(*a)++;
}

void	map_to_chart(t_vars *vars, int fd)
{
	int	a;
	int	i;
	int	b;

	a = 0;
	b = 0;
	i = 0;
	while (vars->line || a == 0)
	{
		skip_lines(vars, fd, &b);
		vars->line = get_next_line(fd);
		if (vars->line == NULL)
			break ;
		vars->map[a] = (char *)ft_calloc(1, sizeof(char)
				* (ft_strlen(vars->line) + 1));
		copy_line_to_map(vars, &a, &i);
		free(vars->line);
	}
	vars->map[a] = NULL;
}
