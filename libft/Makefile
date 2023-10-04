NAME	=	libft.a
CFLAGS	=	-Werror -Wall -Wextra
CC		=	gcc
SRCS	=	ft_atoi.c ft_calloc.c ft_isdigit.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_split.c ft_strdup.c ft_strlcpy.c ft_strlen.c ft_substr.c ft_bzero.c \
			ft_memset.c

OBJS	=	$(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean bonus