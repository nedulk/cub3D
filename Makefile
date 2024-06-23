# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 17:44:47 by kprigent          #+#    #+#              #
#    Updated: 2024/06/23 13:50:54 by kprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAMEB = cub3D_bonus

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
			exec/utils.c\
			exec/check_diagonals.c\

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
CFLAGS = -I ./mlx/ -g -O3 -fPIE

SKY		?= 0
ifeq ($(SKY), 1)
    CFLAGS += -DSKY=1
else ifeq ($(SKY), 2)
    CFLAGS += -DSKY=2
else
    CFLAGS += -DSKY=0
endif

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INCLUDE = -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -pie

$(NAME): $(OBJTS) $(MLX_LIB)
	gcc -o $(NAME) $(OBJTS) $(CFLAGS) $(HEADER) $(LDFLAGS)

$(NAMEB): $(OBJTSB) $(MLX_LIB)
	gcc -o $(NAMEB) $(OBJTSB) $(CFLAGS) $(HEADER) $(LDFLAGS)

RM	=	rm -f

all:	${NAME}

bonus: ${NAMEB}

mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "\nYou need to have MiniLibX installed to execute cub3D :"; \
		echo "----------------------------------------"; \
		echo -n "So do you want to install MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then \
			git clone https://github.com/42Paris/minilibx-linux $(MLX_DIR) && $(MAKE) -C $(MLX_DIR); \
		fi; \
		echo "----------------------------------------"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJTS} ${OBJTSB}

fclean: clean
	${RM} ${NAME} ${NAMEB}

re: fclean all

.PHONY: all bonus clean fclean re