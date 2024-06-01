/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close_release_button.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:13:14 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/01 18:44:04 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_with_esc(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_exit(vars);
	return (0);
}

int	close_with_x(t_vars *vars)
{
	ft_exit(vars);
	return (0);
}
