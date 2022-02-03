
NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putint.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re