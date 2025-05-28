NAME = so_long

NAME_BONUS = bonus_so_long

SRC = mandatory/src/so_long.c \
      mandatory/src/map.c \
      mandatory/src/sprites.c \
      mandatory/src/player.c \
      mandatory/src/handle_errors.c \
      mandatory/src/collectible.c \
      mandatory/src/utils.c \
      libft/ft_split.c \
      libft/ft_putstr_fd.c \
      libft/ft_strlen.c \
      libft/ft_putchar_fd.c \
      libft/gnl/get_next_line.c \
      libft/gnl/get_next_line_utils.c \
      libft/printf/ft_printf.c \
      libft/printf/ft_putchar.c \
      libft/printf/ft_putstr.c \
      libft/printf/ft_putptr.c \
      libft/printf/ft_putnbr.c \
      libft/printf/ft_putnbr_us.c \
      libft/printf/ft_putnbr_base.c \
      libft/ft_lstclear.c \
      libft/ft_lstdelone.c \
      libft/ft_strchr.c \
      libft/ft_strncmp.c 

OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/so_long_bonus.c \
            map_bonus.c \
            sprites_bonus.c 

OBJ_BONUS = $(SRC_BONUS:.c=.o)
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_EX = minilibx-linux/libmlx.a

INC = mandatory/so_long.h \
    libft/libft.h \
    libft/printf/ft_printf.h \
	libft/gnl/get_next_line.h 

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_EX) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_BONUS) $(MLX_EX) -o $(NAME_BONUS)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
