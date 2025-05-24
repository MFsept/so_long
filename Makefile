NAME = so_long

SRC = so_long.c \
		libft/ft_split.c \
		map.c \
		libft/ft_putstr_fd.c \
		libft/gnl/get_next_line.c \
		libft/ft_strlen.c \
		libft/ft_putchar_fd.c \
		libft/gnl/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_EX = minilibx-linux/libmlx.a

INC = so_long.h \
    libft/libft.h \
    libft/printf/ft_printf.h \
	libft/gnl/get_next_line.h 

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_EX) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
