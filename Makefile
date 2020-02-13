SRCS	=	ft_getleng.c \
			ft_countstring.c \
			ft_strdupchar.c \
			ft_strdup_to.c \
			ft_strjoinchar.c \
			ft_strjoin_to.c \
			ft_getflag.c \
			ft_getwidth.c \
			ft_getprecision.c \
			ft_gettype.c \
			ft_verifflagnull.c \
			ft_bblank.c \
			ft_malloc_space.c \
			ft_sizeprints.c \
			ft_printf_c.c \
			ft_printsleft.c \
			ft_printf_s.c \
			ft_revtabpointer.c \
			ft_ptr_addr.c \
			ft_printf_p.c \
			ft_putzeroflag.c \
			ft_putzeroprec.c \
			ft_replacespacezero.c \
			ft_switchspace.c \
			ft_printf_d_i.c \
			ft_itou.c \
			ft_itoa_long.c \
			ft_printf_u.c \
			ft_converthexa.c \
			ft_converthexaupper.c \
			ft_revtab.c \
			ft_itox.c \
			ft_itoxupper.c \
			ft_ishexa.c \
			ft_ishexaupper.c \
			ft_putzeroflagx.c \
			ft_putzeroprecx.c \
			ft_putzeroprecxup.c \
			ft_repspczerox.c \
			ft_repspczeroxup.c \
			ft_printf_x.c \
			ft_printf_xup.c \
			ft_printfspe.c \
			ft_getspe.c \
			ft_printflen.c \
			ft_printf.c \
			ft_strjoins1.c \
			ft_strjoins2.c \
			ft_getnbr0.c \
			ft_joinprintf.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_countnbr.c \
			ft_isdigit.c \
			ft_putchar_fd.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_strjoinnomalloc.c

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
