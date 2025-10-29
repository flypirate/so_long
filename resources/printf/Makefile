# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 14:03:28 by albegar2          #+#    #+#              #
#    Updated: 2025/05/12 17:44:42 by albegar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of file
NAME = libftprintf.a
# Compilation flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
# Source files and object files
SRC = ft_printf.c ft_strlen.c print_char.c print_hex.c print_int.c print_pointer.c \
		print_string.c print_unsigned.c print_percent.c
OBJ = $(SRC:.c=.o)
# Create libraries and delete files
AR = ar rcs
RM = rm -f
# Avoid errors with same named files (following rules are not real files)
.PHONY: all clean fclean re
# Rule to compile all
all: $(NAME)
# Rule to create library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
# Convert files .c to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<
# Rule to delete all obj files created
clean: 
	$(RM) $(OBJ)
# To delete all files .o and .a
fclean: clean
	$(RM) $(NAME)
# To compile all from zero
re: fclean all