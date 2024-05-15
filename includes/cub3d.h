/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:56:31 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 11:54:21 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <../mlx/mlx_int.h>
# include "libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;

////////////IMG MENUE HANDLE////////////////	

	void	*play_click;
	void	*play_selec;
	int		play_x;
	int		play_y;
	int		solong_x;
	int		solong_y;
	int		title_x;
	int		title_y;
///////////////////////////
	void	*title;
	void	*you_win;
	char	**map;
	char	*line;
	int		width;
	int		height;
	int		victory;
	int		one;
	int		p;
	int		c;
	int		e;
	int		wrong;
	int		start;
	int		button_clicked;
	int		nb_of_collectible;
	int		l;
	int		ll;
	int		p_y;
	int		p_x;
	int		map_x;
	int		map_y;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	pe;
	int	c;

}	t_point;


////// MENU AND PARSING //////

int		count_c(t_vars *vars);
void	free_map(t_vars *vars);
int		is_square(t_vars *vars);
void	go_in_game(t_vars *vars);
void	event_game(t_vars *vars);
int		mouse_click(int button, int x, int y, t_vars *vars);
int		mouse_over(int x, int y, t_vars *vars);
int		check_error(char *map, t_vars *vars);
void	find_p(t_vars *vars);
void	find_a_way(t_vars *vars, int x, int y);
int		nb_line(int fd);
int		check_epc(t_vars *vars);
void	free_vars(t_vars *vars);
void	free_modified_map(t_vars *vars);
void	destroy_image(t_vars *vars);
int		close_with_x(t_vars *vars);
int		close_with_esc(int keycode, t_vars *vars);

////// GAME //////

#endif
