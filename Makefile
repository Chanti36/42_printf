CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_aux.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)