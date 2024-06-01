/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param_nsew.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:10:51 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/01 18:02:47 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void handle_texture(char *line, t_vars *vars)
{
    if (ft_strncmp(line, "NO ", 3) == 0 && vars->no == 0)
    {	
        vars->no = 1;
        vars->pass = 1;
        vars->texture[0] = stock_path(line, 2);
    }
    else if (ft_strncmp(line, "SO ", 3) == 0 && vars->so == 0)
    {
        vars->so = 1;
        vars->pass = 1;
        vars->texture[1] = stock_path(line, 2);
    }
    else if (ft_strncmp(line, "WE ", 3) == 0 && vars->we == 0)
    {
        vars->we = 1;
        vars->pass = 1;
        vars->texture[2] = stock_path(line, 2);
    }
    else if (ft_strncmp(line, "EA ", 3) == 0 && vars->ea == 0)
    {
        vars->ea = 1;
        vars->pass = 1;
        vars->texture[3] = stock_path(line, 2);
    }
}

void handle_fc(char *line, t_vars *vars)
{
    if (ft_strncmp(line, "F ", 2) == 0 && vars->f == 0)
    {
        vars->f = 1;
        vars->pass = 1;
        vars->texture[4] = stock_path(line, 1);
    }
    else if (ft_strncmp(line, "C ", 2) == 0 && vars->c == 0)
    {
        vars->c = 1;
        vars->pass = 1;
        vars->texture[5] = stock_path(line, 1);
    }
}

int handle_map(char *line, t_vars *vars, int i)
{
    if (found_map(line) == 1)
    {
        if (vars->no == 1 && vars->so == 1 && vars->we == 1 && vars->ea == 1 && vars->f == 1 && vars->c == 1)
        {
            free(line);
            vars->line_map = i;
            return (0);
        }
        else
        {
            printf(RED"Error\n"RESET);
            printf(YELLOW"Missing parameter\n"RESET);
            free(line);
            return (1);
        }
    }
    return (-1);
}

