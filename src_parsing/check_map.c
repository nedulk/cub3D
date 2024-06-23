/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:22:33 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/23 13:47:31 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_nsew(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_left_right(t_vars *vars, int a, int i)
{
	if (i < 1 || vars->map[a][i + 1] == '\0')
		return (1);
	if (vars->map[a][i - 1] != '0' && vars->map[a][i - 1] != '1'
		&& is_nsew(vars->map[a][i - 1]) == 0)
		return (1);
	if (vars->map[a][i + 1] != '0' && vars->map[a][i + 1] != '1'
		&& is_nsew(vars->map[a][i + 1]) == 0)
		return (1);
	return (0);
}

int	check_top_bottom(t_vars *vars, int a, int i)
{
	if (a < 1 || vars->map[a + 1] == NULL)
		return (1);
	if (vars->map[a - 1][i] != '0' && vars->map[a - 1][i] != '1'
		&& is_nsew(vars->map[a - 1][i]) == 0)
		return (1);
	if (vars->map[a + 1][i] != '0' && vars->map[a + 1][i] != '1'
		&& is_nsew(vars->map[a + 1][i]) == 0)
		return (1);
	return (0);
}

int	check_diagonal(t_vars *vars, int a, int i)
{
	if (vars->map[a - 1][i - 1] != '0' && vars->map[a - 1][i - 1] != '1'
		&& is_nsew(vars->map[a - 1][i - 1]) == 0)
		return (1);
	if (vars->map[a - 1][i + 1] != '0' && vars->map[a - 1][i + 1] != '1'
		&& is_nsew(vars->map[a - 1][i + 1]) == 0)
		return (1);
	if (vars->map[a + 1][i - 1] != '0' && vars->map[a + 1][i - 1] != '1'
		&& is_nsew(vars->map[a + 1][i - 1]) == 0)
		return (1);
	if (vars->map[a + 1][i + 1] != '0' && vars->map[a + 1][i + 1] != '1'
		&& is_nsew(vars->map[a + 1][i + 1]) == 0)
		return (1);
	return (0);
}
