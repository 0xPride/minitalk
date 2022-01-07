CC=gcc
NAME=libftprintf.a
LIBFT=libft/libft.a
CFLAGS=-Wall -Werror -Wextra  -I includes -I libft -c
SRC=src/
C_FILES=$(SRC)main.c $(SRC)ft_ultoa_base.c \
	$(SRC)ft_handle_types.c $(SRC)ft_handle_types2.c
ARFLAGS=rcs

O_FILES=$(patsubst %.c, %.o, $(C_FILES))

all: $(NAME)

$(NAME): $(SRC)$(O_FILES)
	$(MAKE) -C libft bonus
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(O_FILES)

$(SRC)%.o: $(SRC)%.c


re: fclean all

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(O_FILES)
