NAME = push_swap

SRCS =  command.c \
        main.c \
        radix.c \
        five_or_less.c \
        list.c \
        utils.c

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) $(OBJS) libft.a $(CFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME) libft.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
