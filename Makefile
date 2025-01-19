NAME = philo
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=thread -g
CC = cc
RM = rm -rf

SRCS = main.c \
			utile.c \
			check_argv.c \
			initialize.c \
			lifestyle.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
