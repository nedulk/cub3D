/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:19:13 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/05 12:35:09 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*remove_space(char *input)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	output = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (i < (int)ft_strlen(input))
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			output[j] = input[i];
			j++;
		}
		i++;
	}
	output[j] = '\0';
	return (output);
}

int	test_path(char *path)
{
	int	fd;

	path = remove_space(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Texture path is invalid\n"RESET);
		free(path);
		path = NULL;
		return (1);
	}
	close(fd);
	free(path);
	path = NULL;
	return (0);
}

char	*extract_number(char *tab, int *i, int *n)
{
	int		a;
	char	*test_nb;

	a = 0;
	test_nb = malloc(sizeof(char) * 5);
	while (tab[*i] >= '0' && tab[*i] <= '9')
	{
		if (*n < 5)
			test_nb[a] = tab[*i];
		(*i)++;
		(*n)++;
		a++;
	}
	test_nb[a] = '\0';
	return (test_nb);
}

int	test_color(char *tab)
{
	int		i;
	int		n;
	char	*test_nb;

	n = 0;
	i = 0;
	tab = remove_space(tab);
	while (tab[i])
	{
		test_nb = extract_number(tab, &i, &n);
		if (ft_atoi(test_nb) > 255 || n > 3 || ((tab[i] < '0'
					|| tab[i] > '9') && tab[i] != ',' && tab[i] != '\0'))
		{
			printf(YELLOW"Error\nColor is invalid\n"RESET);
			free(test_nb);
			free(tab);
			return (1);
		}
		if (tab[i] != '\0')
			i++;
		n = 0;
		free(test_nb);
	}
	free(tab);
	return (0);
}

int	check_param_valid(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (test_path(vars->texture[i]) == 1)
			return (1);
		i++;
	}
	if (test_color(vars->texture[4]) == 1 || test_color(vars->texture[5]) == 1)
		return (1);
	return (0);
}
