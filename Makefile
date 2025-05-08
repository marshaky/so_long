NAME = so_long

SRCSPATH = ./src/
PRINTF_PATH = ./ft_printf/
LIBFT_PATH = ./ft_printf/libft/
MLXPATH = ./mlx/
INCPATH = ./includes/ $(PRINTF_PATH) $(MLXPATH) $(LIBFT_PATH)

SRCS = \
	$(SRCSPATH)get_next_line.c \
	$(SRCSPATH)get_next_line_utils.c \
	$(SRCSPATH)main.c \
	$(SRCSPATH)map.c \
	$(SRCSPATH)render.c

OBJS = $(SRCS:.c=.o)

PRINTF = $(PRINTF_PATH)/libftprintf.a
MLX = $(MLXPATH)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION $(foreach H,$(INCPATH),-I$(H))
MLXFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PRINTF_PATH)
	@make -C $(MLXPATH)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(MLX) -I$(MLXPATH) -o $(NAME) $(MLXFLAGS)

$(SRCSPATH)%.o: $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(MLXPATH)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
