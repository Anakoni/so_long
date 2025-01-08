# Variables

NAME = so_long

INCLUDE = includes

LIBFT = libs/libft
LIBX = libs/minilibx

MAC = -framework OpenGL -framework AppKit 

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

GREEN = \033[32m
RED = \033[31m
DEF_COLOR = \033[0m
TERM_UP = \033[A

# Sources 

SRC_DIR = src/
SRC_FILES = map.c so_long.c render.c player.c portal.c check.c utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC:.c=.o)

# Fonctions

all: $(NAME)
	@echo "$(TERM_UP)$(GREEN)Compilation successful !$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (echo "$(TERM_UP)$(RED)Error in libft compilation!$(DEF_COLOR)" && exit 1)
	@$(MAKE) -C $(LIBX) -s all || (echo "$(TERM_UP)$(RED)Error in minilibx compilation!$(DEF_COLOR)" && exit 1)
	@$(CC) $(CFLAGS) $(MAC) $(OBJS) -L $(LIBFT) -lft -L $(LIBX) -lmlx -o $(NAME) || \
		(echo "$(TERM_UP)$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "$(TERM_UP)$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

clean:
	@rm -f $(OBJS)
	@echo "$(TERM_UP)$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(TERM_UP)$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
