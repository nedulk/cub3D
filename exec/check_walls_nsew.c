/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_nsew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:13:19 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 11:34:43 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_so(t_vars *vars, double i, double y)
{
	int	test_xmap;
	int	test_ymap;

	test_xmap = vars->x_map;
	test_ymap = vars->y_map;
	if ((i - 0.01) < 0)
	{
		if ((y + 0.01 > 1))
		{
			if (vars->map[test_ymap - 1][test_xmap] == '1'
				&& vars->map[test_ymap][test_xmap + 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}

int	check_ne(t_vars *vars, double i, double y)
{
	int	test_xmap;
	int	test_ymap;

	test_xmap = vars->x_map;
	test_ymap = vars->y_map;
	if ((i + 0.01) > 1)
	{
		if ((y - 0.01 < 0))
		{
			if (vars->map[test_ymap + 1][test_xmap] == '1'
				&& vars->map[test_ymap][test_xmap - 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}

int	check_no(t_vars *vars, double i, double y)
{
	int	test_xmap;
	int	test_ymap;

	test_xmap = vars->x_map;
	test_ymap = vars->y_map;
	if ((i - 0.01) < 0)
	{
		if ((y - 0.01 < 0))
		{
			if (vars->map[test_ymap + 1][test_xmap] == '1'
				&& vars->map[test_ymap][test_xmap + 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}

int	check_se(t_vars *vars, double i, double y)
{
	int	test_xmap;
	int	test_ymap;

	test_xmap = vars->x_map;
	test_ymap = vars->y_map;
	if ((i + 0.01) >= 1)
	{
		if ((y + 0.01 >= 1))
		{
			if (vars->map[test_ymap - 1][test_xmap] == '1'
				&& vars->map[test_ymap][test_xmap - 1] == '1')
			{
				vars->diagonals = 1;
				return (1);
			}
		}
	}
	return (0);
}
