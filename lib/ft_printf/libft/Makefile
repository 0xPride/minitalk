CC=gcc
NAME=libft.a
CFLAGS=-Wall -Werror -Wextra -c
C_FILES=ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c    \
	ft_isascii.c    \
	ft_isdigit.c    \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c    \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c    \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_atoi.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c    \
	ft_strncmp.c    \
	ft_strnstr.c \
	ft_strrchr.c    \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c\

B_FILES=ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	$(C_FILES)

O_FILES=$(patsubst %.c, %.o, $(C_FILES))
O_FILES_B=$(patsubst %.c, %.o, $(B_FILES))

all: $(NAME)

$(NAME): $(O_FILES)

bonus: $(O_FILES_B)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	ar rc $(NAME) $@

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o
