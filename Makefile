SRCS	=	$(wildcard ft_*.c)


OBJ	= ${SRCS:.c=.o}

INCS	= libftprintf.h

NAME	= libftprintf.a

CC = gcc

CFLAGS	= 	-Wall -Werror -Wextra

%.o: %.c	$(INCS)
		$(CC) $(CFLAGS) -I $(INCS) -o $@ -c $<

$(NAME):	libft ${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:		
			@make clean -C libft
			rm -rf ${OBJ}

fclean:		clean
			@make fclean -C libft
			rm -rf ${NAME}

re:			fclean all

libft:		
			@make -C libft

.PHONY:		all clean fclean libft
