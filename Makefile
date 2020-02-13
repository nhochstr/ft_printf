SRCS	=	ft_calloc_space.c \
			ft_convert_hexa.c \
			ft_count_nbr_string.c \
			ft_get_all_flags.c \
			ft_get_leng_null.c \
			ft_is_digit.c \
			ft_ito_ato.c \
			ft_joins.c \
			ft_joins_no_malloc.c \
			ft_printf.c \
			ft_printf_c.c \
			ft_printf_digits.c \
			ft_printf_p.c \
			ft_printf_s.c \
			ft_printf_specs.c\
			ft_put_zero.c \
			ft_putchar_fd.c \
			ft_replace_space_zero.c \
			ft_rev_tab.c \
			ft_set_digit.c \
			ft_sizeprints.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_verifflagnull.c

OBJ	= ${SRCS:.c=.o}

INCS = libftprintf.h

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c	$(INCS)
		$(CC) $(CFLAGS) -I $(INCS) -o $@ -c $<

$(NAME):	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:		
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
