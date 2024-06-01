/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:41:14 by dboire            #+#    #+#             */
/*   Updated: 2024/06/01 11:52:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	texture_north()
// {
// 	while (j < draw_end)
// 		{
// 			int tex_y;
// 			if (distance_to_wall <= 40)
// 			{
// 				double proportion = distance_to_wall / 40;
// 				int tex_start = (tex_height - tex_height * proportion) / 2;
// 				int tex_end = tex_height - tex_start;
// 				tex_y = tex_start + ((j - draw_start) * (tex_end - tex_start))
// 					/ line_height;
// 			}
// 			else
// 				tex_y = ((j - draw_start) * tex_height) / line_height;

// 			int po;

// 			po = vars->pos_x * RESOLUTION;
// 			my_mlx_pixel_put(vars, x, j, vars->texture_N[tex_y][po]);
// 			j++;
// 		}
// }