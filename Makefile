CC=gcc
SERVER=server
CLIENT=client
CFLAGS=-Wall -Werror -Wextra -c -I include -I lib/ft_printf/includes -I lib/ft_printf/libft/
SRC=src/
FT_PRINTF=libftprintf.a
FT_PRINTF_DIR=lib/ft_printf/
S_CFILES=$(SRC)$(SERVER).c $(FT_PRINTF_DIR)$(FT_PRINTF)
C_CFILES=$(SRC)$(CLIENT).c $(FT_PRINTF_DIR)$(FT_PRINTF)
S_OFILES=$(patsubst %.c, %.o, $(S_CFILES))
C_OFILES=$(patsubst %.c, %.o, $(C_CFILES))

all:$(SERVER) $(CLIENT)
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER): $(S_OFILES) $(FT_PRINTF)
	$(CC) $(S_OFILES) -o $(SERVER)

$(CLIENT): $(C_OFILES)
	$(CC) $(C_OFILES) -o $(CLIENT)

$(SRC)%.o: $(SRC)%.c

$(FT_PRINTF_DIR)$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

re: fclean all

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

clean:
	rm -f $(S_OFILES)
	rm -f $(C_OFILES)
