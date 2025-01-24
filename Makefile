CC=cc
FLAGES=-Wall -Wextra -Werror -g
SRC=pipex.c uitls.c error_check.c
OBSRC=$(SRC:.c=.o)
LIBFT_DIR=libft
LIBFT_A=$(LIBFT_DIR)/libft.a
NAME=pipex

all: $(NAME)

$(NAME): $(OBSRC) $(LIBFT_A)
	$(CC) $(FLAGES) $(OBSRC) -o $@ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FLAGES) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBSRC)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re fclaen claen

