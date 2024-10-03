NAME = pipex

MY_SOURCES  = $(shell find ./src -name *.c)

MY_OBJS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

LIBFT_DIR = ./lib/libft
PRINTF_DIR = ./lib/printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(PRINTF):
	@make -sC $(PRINTF_DIR)

$(NAME): $(MY_OBJS) $(LIBFT) $(PRINTF)
	@echo "Compilando el programa..."
	@gcc $(CFLAGS) $(MY_OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "...Compilado con éxito :)"

%.o: %.c
	@gcc $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	@echo "Limpiando archivos generados..."
	@rm -f $(MY_OBJS) ./outfile
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(PRINTF_DIR)
	@echo "...Todo limpito :)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)

re: fclean all
	@echo "Recompilando..."

.PHONY: all clean fclean re