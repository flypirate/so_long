# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 18:50:01 by albegar2          #+#    #+#              #
#    Updated: 2025/09/15 16:42:53 by albegar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -I resources/libft -I resources/gnl \
			-I MLX42/include -I resources/printf

LFLAGS = -L resources/gnl -lgnl -L resources/libft -lft \
         	-L resources/printf -lftprintf -L MLX42/build -lmlx42 \
				-lglfw -ldl -lm -lGL -lpthread

SRCS = src/so_long.c src/graphics.c src/playermoves.c src/aux_functions.c \
		src/free_functions.c src/map_functions.c src/flood_fill.c \
			src/mlx_functions.c

OBJFILES = $(SRCS:.c=.o)

LIBFT_DIR = resources/libft

GNL_DIR = resources/gnl

PRINTF_DIR = resources/printf

MLX_DIR = MLX42

LIBFT_A = $(LIBFT_DIR)libft.a

GNL_A   = $(GNL_DIR)/libgnl.a

PRINTF_A = $(PRINTF_DIR)/libftprintf.a

MLX_A = $(MLX_DIR)/libmlx42.a

all: $(LIBFT_A) $(GNL_A) $(PRINTF_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(GNL_A):
	@make -C $(GNL_DIR)

$(PRINTF_A):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJFILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re