NAME		= so_long

SRCS		= ./srcs/check_map.c ./srcs/create_map.c ./srcs/handle_actions.c \
				./srcs/init_structure.c ./srcs/render_map.c ./srcs/so_long.c ./srcs/utils.c
SRCS_BONUS	= ./srcs_bonus/check_map_bonus.c ./srcs_bonus/create_map_bonus.c \
				./srcs_bonus/handle_actions_bonus.c ./srcs_bonus/init_structure_bonus.c \
				./srcs_bonus/render_map_bonus.c ./srcs_bonus/so_long_bonus.c \
				./srcs_bonus/utils_bonus.c

OBJS		= $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS	= $(patsubst %.c,%.o,$(SRCS_BONUS))

D_FILES		= $(patsubst %.c,%.d,$(SRCS) $(SRCS_BONUS))

LIB_DIR		= ./libft

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

%.o: 		%.c
			@$(CC) $(CFLAGS) -c $< -o $@ -MD

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $? $(LIB_DIR)/libft.a -o $(NAME)

bonus:		$(OBJS_BONUS)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $? $(LIB_DIR)/libft.a -o $(NAME)

clean:
			@rm -rf $(OBJS) $(OBJS_BONUS) $(D_FILES)
			@make clean -C $(LIB_DIR)

fclean: 	clean
			@rm -rf $(NAME)
			@make fclean -C $(LIB_DIR)

-include $(D_FILES)

re: 		fclean all

.PHONY: 	all clean fclean re bonus