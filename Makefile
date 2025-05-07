NAME			= so_long

SRCS			= main.c map.c render.c
OBJS			= $(SRCS:.c=.o)

FT_PRINTF_DIR	= ft_printf
FT_PRINTF_LI	= $(FT_PRINTF_DIR)/libftprintf.a

MLX				= -lmlx -framework OpenGL -framework AppKit

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
					@$(MAKE) -C $(FT_PRINTF_DIR)
					$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME) $(MLX)

clean:
				@$(MAKE) clean -C $(FT_PRINTF_DIR)
				$(RM) $(OBJS)

fclean:			clean
					@$(MAKE) fclean -C $(FT_PRINTF_DIR)
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re