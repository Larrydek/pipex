NAME = pipex

MY_SOURCES  = $(shell find ./src -name *.c)

MY_OBJS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

LIBFT_DIR = ./lib/libft
PRINTF_DIR = ./lib/printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m 

all: $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(PRINTF):
	@make -sC $(PRINTF_DIR)

$(NAME): $(MY_OBJS) $(LIBFT) $(PRINTF)
	@echo "$(YELLOW)Compilando el programa..."
	@gcc $(CFLAGS) $(MY_OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)Compilado con éxito :)$(NC)"

%.o: %.c
	@gcc $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Limpiando archivos generados..."
	@rm -f $(MY_OBJS) ./outfile
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(PRINTF_DIR)
	@echo "$(RED)Todo limpito :)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)

re: fclean all
	@echo "$(YELLOW)Recompilando...$(NC)"
	
.PHONY: all clean fclean re