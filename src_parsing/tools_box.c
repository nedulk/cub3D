/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:55:38 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/01 17:29:27 by kprigent         ###   ########.fr       */
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
