/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_texture_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:00:53 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/12 12:27:21 by kprigent         ###   ########.fr       */
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

void	check_resolution2(t_vars *vars, t_texture_data *data, int reso)
{
	if (reso == 7680)
	{
		if (data->width != 7680 || data->height != 540)
		{
			printf(RED"Error\n(360) Sky resolution must be 7680x540\n"RESET);
			mlx_destroy_image(vars->mlx, data->img);
			ft_exit(vars);
		}
	}
	else if (reso == 1421)
	{
		if (data->width != 1421 || data->height != 360)
		{
			printf(RED"Error\nSprite resolution must be 1400x360\n"RESET);
			mlx_destroy_image(vars->mlx, data->img);
			ft_exit(vars);
		}
	}
}

void	check_resolution(t_vars *vars, t_texture_data *data, int reso)
{
	if (reso == RESOLUTION)
	{
		if (data->width != 256 || data->height != 256)
		{
			printf(RED"Error\nTexture resolution must be 256x256\n"RESET);
			mlx_destroy_image(vars->mlx, data->img);
			ft_exit(vars);
		}
	}
	else if (reso == 1920)
	{
		if (data->width != 1920 || data->height != 540)
		{
			printf(RED"Error\nSky resolution must be 1920x540\n"RESET);
			mlx_destroy_image(vars->mlx, data->img);
			ft_exit(vars);
		}
	}
	check_resolution2(vars, data, reso);
}

int	**load_texture(t_vars *vars, char *texture_path, int reso)
{
	t_texture_data	data;

	data.width = 0;
	data.height = 0;
	data.bits_per_pixel = 32;
	data.endian = 1;
	data.size_line = reso * (32 / 8);
	data.img = mlx_xpm_file_to_image(vars->mlx, texture_path,
			&data.width, &data.height);
	if (data.img == NULL)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Texture %s not found\n"RESET, texture_path);
		ft_exit(vars);
	}
	check_resolution(vars, &data, reso);
	data.img_data = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.size_line, &data.endian);
	data.texture = initialize_texture(&data);
	fill_texture(&data);
	mlx_destroy_image(vars->mlx, data.img);
	return (data.texture);
}
