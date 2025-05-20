NAME = so_long

SRCSPATH = ./src/
PRINTF_PATH = ./ft_printf/
LIBFT_PATH = ./ft_printf/libft/
MLXPATH = ./mlx/
INCPATH = ./includes/ $(PRINTF_PATH) $(MLXPATH) $(LIBFT_PATH)

SRCS = \
	$(SRCSPATH)draw.c \
	$(SRCSPATH)game.c \
	$(SRCSPATH)handlers.c \
	$(SRCSPATH)key_hook.c \
	$(SRCSPATH)utils.c \
	$(SRCSPATH)validator.c \
	$(SRCSPATH)get_next_line.c \
	$(SRCSPATH)get_next_line_utils.c \
	$(SRCSPATH)so_long.c \
	$(SRCSPATH)map.c \
	$(SRCSPATH)flood_fill.c \
	$(SRCSPATH)img.c

OBJS = $(SRCS:.c=.o)

PRINTF = $(PRINTF_PATH)/libftprintf.a
MLX = $(MLXPATH)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(foreach H,$(INCPATH),-I$(H))

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLXFLAGS = -framework OpenGL -framework AppKit
else
	MLXFLAGS = -lX11 -lXext -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(MLX) -o $(NAME) $(MLXFLAGS)

$(SRCSPATH)%.o: $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(PRINTF_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
