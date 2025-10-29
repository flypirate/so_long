# Name of file
NAME = libft.a
# Compilation flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
# Source files and object files
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c \
		 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c 
OBJ = $(SRC:.c=.o)
# Head file
INCLUDE = libft.h
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