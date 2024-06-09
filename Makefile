# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 17:44:47 by kprigent          #+#    #+#              #
#    Updated: 2024/06/09 11:40:01 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAIN_SRCS = src_parsing/main.c \
			src_parsing/event_close_release_button.c \
			src_parsing/mouse_menu_event.c \
			src_parsing/check_error.c \
			src_parsing/tools_box.c \
			src_parsing/free_and_exit.c \
			src_parsing/map_to_chart.c \
			src_parsing/parsing.c \
			src_parsing/texture_img_load.c \
			src_parsing/parsing_param.c \
			src_parsing/parsing_valid.c \
			src_parsing/parsing_param_nsew.c \
			src_parsing/img_texture_handle.c \
			src_parsing/check_map.c \
			libft/ft_strdup.c \
			libft/ft_putcharp.c \
			libft/ft_putnbr_base.c \
			libft/ft_putnbr_unsigned.c \
			libft/ft_putnbrp.c \
			libft/ft_putstrp.c \
			libft/ft_putaddr.c \
			libft/ft_itoa.c \
			libft/ft_calloc.c \
			libft/ft_bzero.c \
			libft/ft_atoi.c \
			libft/ft_split.c \
			libft/ft_strlen.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c\
			libft/ft_strncmp.c \
			exec/exec.c\
			exec/draw.c\
			exec/sprites_handle.c\
			exec/redraw.c\
			exec/bresenham.c\
			exec/rays.c\
			exec/draw_wall.c\
			exec/check_walls.c\
			exec/check_walls_nsew.c\
			exec/calculate_i_y.c\
			exec/wasd.c\
			exec/draw_wall_direction.c\
			exec/draw_grid.c\
			exec/move.c\
			exec/sky.c\
			exec/door.c\
			exec/utils.c\
			exec/check_diagonals.c

MAIN_SRCSB = src_parsing_bonus/main_bonus.c \
			src_parsing_bonus/event_close_release_button_bonus.c \
			src_parsing_bonus/mouse_menu_event_bonus.c \
			src_parsing_bonus/check_error_bonus.c \
			src_parsing_bonus/tools_box_bonus.c \
			src_parsing_bonus/free_and_exit_bonus.c \
			src_parsing_bonus/map_to_chart_bonus.c \
			src_parsing_bonus/parsing_bonus.c \
			src_parsing_bonus/texture_img_load_bonus.c \
			src_parsing_bonus/parsing_param_bonus.c \
			src_parsing_bonus/parsing_valid_bonus.c \
			src_parsing_bonus/parsing_param_nsew_bonus.c \
			src_parsing_bonus/img_texture_handle_bonus.c \
			src_parsing_bonus/check_map_bonus.c \
			libft/ft_strdup.c \
			libft/ft_putcharp.c \
			libft/ft_putnbr_base.c \
			libft/ft_putnbr_unsigned.c \
			libft/ft_putnbrp.c \
			libft/ft_putstrp.c \
			libft/ft_putaddr.c \
			libft/ft_itoa.c \
			libft/ft_calloc.c \
			libft/ft_bzero.c \
			libft/ft_atoi.c \
			libft/ft_split.c \
			libft/ft_strlen.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c\
			libft/ft_strncmp.c \
			exec_bonus/exec_bonus.c\
			exec_bonus/draw_bonus.c\
			exec_bonus/sprites_handle_bonus.c\
			exec_bonus/redraw_bonus.c\
			exec_bonus/bresenham_bonus.c\
			exec_bonus/rays_bonus.c\
			exec_bonus/draw_wall_bonus.c\
			exec_bonus/check_walls_bonus.c\
			exec_bonus/check_walls_nsew_bonus.c\
			exec_bonus/calculate_i_y_bonus.c\
			exec_bonus/wasd_bonus.c\
			exec_bonus/draw_wall_direction_bonus.c\
			exec_bonus/draw_grid_bonus.c\
			exec_bonus/move_bonus.c\
			exec_bonus/sky_bonus.c\
			exec_bonus/door_bonus.c\
			exec_bonus/utils_bonus.c\
			exec_bonus/check_diagonals_bonus.c


OBJTS = $(MAIN_SRCS:.c=.o)
OBJTSB = $(MAIN_SRCSB:.c=.o)

HEADER = -I includes
CFLAGS = -Wall -Wextra -Werror -I ./mlx/ -g -O3 -fPIE

$(NAME): $(OBJTS)
	gcc -o $(NAME) $(OBJTS) $(CFLAGS) $(HEADER) -L ./mlx -lmlx -lXext -lX11 -lm -lbsd -pie

$(NAMEB): $(OBJTSB)
	gcc -o $(NAMEB) $(OBJTSB) $(CFLAGS) $(HEADER) -L ./mlx -lmlx -lXext -lX11 -lm -lbsd -pie

RM	=	rm -f

all:	${NAME}

bonus: ${NAMEB}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJTS} ${OBJTSB}
	
fclean:	clean
	${RM} ${NAME} ${NAMEB}

re:	fclean all

.PHONY: all bonus clean fclean re
