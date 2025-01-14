NAME = philo
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
CC = cc
RM = rm -rf

SRCS = src.c \
			utile.c

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
