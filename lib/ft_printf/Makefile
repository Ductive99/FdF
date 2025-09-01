NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putnbr.c\
	src/ft_puthex.c src/ft_putptr.c src/do_op.c

OBJS = $(SRCS:.c=.o)

INCDIR = include

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

run: 
	$(CC) $(CFLAGS) $(SRCS) -I $(INCDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all