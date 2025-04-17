NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBFT_DIR	= Libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
PRINTF		= ft_printf
PRINF_A		= $(PRINTF)/libftprintf.a

SRC		= src/validator.c \
			src/parse_data.c \
			src/push_swap.c \
			src/array_utils.c \
			src/stack_utils.c \
			src/free_stack.c \
			src/ft_puterror.c 

MAKEFLAGS += --no-print-directory

INCLUDE = -I include -I $(PRINTF)
OBJS	= $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[1;31m
BLUE_UNDER = \033[1;34m
YELLOW = \033[0;33m
CYAN = \033[1;36m
MAGENTA = \033[0;35m
WHITE = \033[1;37m
WHITE_RED_BG = \033[0;41;37m
YELLOW_UNDER = \033[1;4;33m
NC = \033[0m

all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINF_A):
	@$(MAKE) -C $(PRINTF)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINF_A)
	@echo "$(MAGENTA)Compiling $(NAME)$(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -L$(LIBFT_DIR) -L$(PRINTF) -lft -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing .o files in all directories$(NC)"
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF)

fclean: clean
	@echo "$(RED)Removing .a files and executables$(NC)"
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF)

re: fclean all
