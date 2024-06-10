/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_texture_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:00:53 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/08 14:19:07 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	**initialize_texture(t_texture_data *data)
{
	int		y;

	data->texture = ft_calloc(1, data->height * sizeof(int *));
	y = 0;
	while (y < data->height)
	{
		data->texture[y] = ft_calloc(1, data->width * sizeof(int));
		y++;
	}
	return (data->texture);
}

void	fill_texture(t_texture_data *data)
{
	int		y;
	int		x;
	int		index;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			index = (y * data->size_line + x * (data->bits_per_pixel / 8));
			data->texture[y][x] = *(int *)(data->img_data + index);
			x++;
		}
		y++;
	}
}

int	**load_texture(t_vars *vars, char *texture_path)
{
	t_texture_data	data;

	data.width = RESOLUTION;
	data.height = RESOLUTION;
	data.bits_per_pixel = 32;
	data.endian = 1;
	data.size_line = RESOLUTION * (32 / 8);
	data.img = mlx_xpm_file_to_image(vars->mlx, texture_path,
			&data.width, &data.height);
	data.img_data = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	data.texture = initialize_texture(&data);
	fill_texture(&data);
	mlx_destroy_image(vars->mlx, data.img);
	return (data.texture);
}