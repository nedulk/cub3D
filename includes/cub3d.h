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
# include "../mlx/mlx_int.h"
# include "libft.h"
# include <stdint.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define SPEED 5
# define RAYS 1
# define EDGE 40
# define FOV 90
# define PI 3.14159265
# define RESOLUTION 256
# define SPRITE_HEIGHT 600
# define SPRITE_WIDTH 1421
# define TRANSPARENT_COLOR 0x00000000

# define LOAD_X 700
# define LOAD_Y 500

// SKY = 0 basic color | SKY = 1 sky texture | SKY = 2 sky 360°  
# define SKY 0

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define DOOR_X 4
# define DOOR_Y 5

# define RESET   "\x1B[0m"
# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define WHITE   "\x1B[37m"

# define R   "\x1B[31m"
# define G   "\x1B[32m"
# define Y   "\x1B[33m"
# define RESET "\x1B[0m"

typedef struct s_texture_data
{
	void	*img;
	char	*img_data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		**texture;
}				t_texture_data;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*loading;
	void			*loading_1;
	void			*loading_2;
	void			*loading_3;
	void			*loading_sky;
	void			*loading_360;
	void			*wall;
	void			*floor;
	void			*celing;
	void			*play_click;
	void			*play_selec;
	int				play_button_x;
	int				play_button_y;
	int				title_x;
	int				title_y;
	int				pass;
	char			**texture;
	int				**texture_n;
	int				**texture_s;
	int				**texture_e;
	int				**texture_w;
	int				**texture_d;
	int				**texture_sky;
	int				***sprite;
	double			pos_x;
	double			pos_y;
	int				line_map;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	void			*title;
	char			**map;
	int				celing_color;
	int				floor_color;
	char			*line;
	int				width;
	int				height;
	char			*buff;
	int				button_clicked;
	double			wall_hit_x;
	double			wall_hit_y;
	int				moving_forward;
	int				moving_backward;
	int				moving_left;
	int				moving_right;
	int				map_press;
	float			rays_number;
	float			draw;
	int				prev_pos_x;
	int				prev_pos_y;
	float			play_x;
	float			play_y;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*img;
	void			*img2;
	void			*addr;
	int				x_map;
	int				y_map;
	double			rotate_x1;
	double			rotate_y1;
	double			x0;
	double			x1;
	double			y0;
	double			y1;
	float			ray_x0;
	float			ray_y0;
	float			ray_y;
	float			ray_x;
	float			ray_x1;
	float			ray_y1;
	int				x;
	int				y;
	double			angle;
	double			vision_angle;
	double			dx;
	double			dy;
	int				draw_start;
	int				draw_end;
	int				direction;
	double			incx;
	double			incy;
	double			rotate;
	double			angle_step;
	int				diagonals;
	int				length_x;
	int				length_y;
	int				first_x;
	int				last_x;
	int				last_po;
	int				last_j;
	int				last_xwall;
	int				door;
	int				doorx;
	int				doory;
	int				bool;
	int				color_img;
	double long		cos;
	double long		sin;
	t_texture_data	*texture_data;
	uint32_t		color;
	uint32_t		color1;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	pe;
	int	c;

}	t_point;


int	check_walls_player(t_vars *vars);
int	mouse_move(int x, int y, t_vars *vars);
int	stop_move(int keycode, t_vars *vars);
void	draw_sky_simple(t_vars *vars);
void	draw_sky_img(t_vars *vars, double angle);
int		is_door(t_vars *vars);
int		draw_door(t_vars *vars, double distance_to_wall, int x, int j);
void	define_fov(t_vars *vars);


//Self-explanatory
void	open_door(t_vars *vars);

// Check diagonals
int		check_so(t_vars *vars, double i, double y);
int		check_se(t_vars *vars, double i, double y);
int		check_ne(t_vars *vars, double i, double y);
int		check_no(t_vars *vars, double i, double y);

//Calculate position of the pixel in the square
double	calculate_i(t_vars *vars, double i);
double	calculate_y(t_vars *vars, double y);

//Calculate position of the player in the square
double	calculate_play_i(t_vars *vars, double i);
double	calculate_play_y(t_vars *vars, double y);

// Moving the player
void	move_forward(t_vars *vars);
void	move_backward(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);

//Texture
int		check_px_wall(t_vars *vars, float x, float y);

// Draw the texture of the wall depending on which direction the player face
int		draw_north_wall(t_vars *vars, double distance_to_wall, int x, int j);
int		draw_south_wall(t_vars *vars, double distance_to_wall, int x, int j);
int		draw_east_wall(t_vars *vars, double distance_to_wall, int x, int j);
int		draw_west_wall(t_vars *vars, double distance_to_wall, int x, int j);
int		draw_door(t_vars *vars, double distance_to_wall, int x, int j);
void	draw_sprites(t_vars *vars);
void	draw_sky_img(t_vars *vars, double angle);

//check where the player needs to face
void	check_player_angle(t_vars *vars, int i, int y);
void	ft_correct_angle(t_vars *vars);
void	ft_draw_horizontal(t_vars *vars);
void	ft_draw_vertical(t_vars *vars);
int		ft_draw_line_bresenham(t_vars *vars);
void	draw_rays(t_vars *vars);
void	redraw_grid_wo_p(t_vars *vars);
void	rotation_matrix(t_vars *vars);
double	ft_absolute_number(double value);
double	ft_sign(double value);

////// EXEC //////////////////
int		exec(t_vars *vars);
void	draw_player(t_vars *vars);
void	draw_floor_tile(t_vars *vars);
void	draw_wall_tile(t_vars *vars);
void	draw_door_tile(t_vars *vars, int color);
void	draw_wall(t_vars *vars, int x, int wall_height,
			double distance_to_wall);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_rays(t_vars *vars);
int		check_walls(t_vars *vars);
void	draw_grid(t_vars *vars);
void	redraw_player(t_vars *vars);
void	redraw_grid(t_vars *vars);
int		check_walls_ray(t_vars *vars);
int		check_walls_path(t_vars *vars);
int		move(int keycode, t_vars *vars);

////// MENU AND PARSING //////

int		**load_texture(t_vars *vars, char *texture_path);
void	fill_texture(t_texture_data *data);
int		**initialize_texture(t_texture_data *data);
int		check_left_right(t_vars *vars, int a, int i);
int		is_nsew(char c);
int		check_top_bottom(t_vars *vars, int a, int i);
int		check_diagonal(t_vars *vars, int a, int i);
void	handle_texture(char *line, t_vars *vars);
void	handle_fc(char *line, t_vars *vars);
int		handle_map(char *line, t_vars *vars, int i, int fd);
int		handle_error(char *error);
char	*stock_path(char *line, int i);
int		found_map(char *line);
void	go_in_game(t_vars *vars);
void	event_game(t_vars *vars);
int		mouse_click(int button, int x, int y, t_vars *vars);
int		mouse_over(int x, int y, t_vars *vars);
int		nb_line(int fd);
int		check_nsew(char **map);
void	ft_exit(t_vars *vars);
void	destroy_image(t_vars *vars);
int		close_with_x(t_vars *vars);
int		close_with_esc(int keycode, t_vars *vars);
int		parsing(t_vars *vars, char **argv, int argc);
int		check_map(char *map, t_vars *vars);
int		check_param(char *map, t_vars *vars);
int		check_param_valid(t_vars *vars);
char	*remove_space(char *tab);
void	map_to_chart(t_vars *vars, int fd);
int		check_param(char *map, t_vars *vars);
void	sprites_sky_floor(t_vars *vars);
void	game_textures(t_vars *vars);
void	load_menu(t_vars *vars);
void	free_double_char(char **tab);
int		free_line(char *line, int fd);
int		handle_error(char *message);
void	free_texture(char **texture);

#endif
