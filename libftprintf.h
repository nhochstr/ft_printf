/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:07:32 by nhochstr          #+#    #+#             */
/*   Updated: 2019/12/13 11:02:56 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct			s_spec
{
	char	flags;
	long	width;
	long	precision;
	char	type;
	char	*ptr;
}						t_spec;

int				ft_getleng(int leng);
int				ft_countstring(char const *s, char *str);
unsigned long	ft_strlento(char *str, char c);
char			*ft_strdupchar(char s);
char			*ft_strdup_to(char *s, char c);
char			*ft_strjoinchar(char const *s1, char const s2);
char			*ft_strjoin_to(char const *s1, char const *s2, char c);
char			ft_getflag(const char *format, int leng);
long			ft_getwidth(const char *format, int leng, va_list args);
long			ft_getprecision(const char *format, int leng, va_list args);
char			ft_gettype(const char *format, int leng);
int				ft_verifflagnull(t_spec spec);
void			ft_bblank(void *s, size_t n);
char			*ft_malloc_space(size_t count, size_t size);
int				ft_sizeprints(t_spec spec, char *copy);
char			*ft_printf_c(t_spec spec, va_list args, char *ptr);
char			*ft_printsleft(t_spec spec, char *copy, char *buff, unsigned int size);
char			*ft_printf_s(t_spec spec, va_list args, char *ptr);
char			*ft_revtabpointer(char *buffptr);
char			*ft_ptr_addr(long addr, char *buffptr, int i);
char			*ft_printf_p(t_spec spec, va_list args, char *ptr);
char			*ft_putzeroflag(char *buff, int neg);
char			*ft_putzeroprec(char *buff, int neg, t_spec spec);
char			*ft_replacespacezero(char *buff, t_spec spec);
char			*ft_switchspace(char *buff);
char			*ft_printf_d_i(t_spec spec, va_list args, char *ptr);
unsigned int	ft_itou(int i);
char			*ft_itoa_long(long n);
char			*ft_printf_u(t_spec spec, va_list args, char *ptr);
char			*ft_converthexa(long nbr, char *buffptr, int i);
char			*ft_converthexaupper(long nbr, char *buffptr, int i);
char			*ft_revtab(char *buffptr);
char			*ft_itox(long nbr);
char			*ft_itoxupper(long nbr);
int				ft_ishexa(int c);
int				ft_ishexaupper(int c);
char			*ft_putzeroflagx(char *buff, int neg);
char			*ft_putzeroprecx(char *buff, int neg, t_spec spec);
char			*ft_putzeroprecxup(char *buff, int neg, t_spec spec);
char			*ft_repspczerox(char *buff, t_spec spec);
char			*ft_repspczeroxup(char *buff, t_spec spec);
char			*ft_printf_x(t_spec spec, va_list args, char *ptr);
char			*ft_printf_xup(t_spec spec, va_list args, char *ptr);
char			*ft_printfspe(t_spec spec, va_list args, char *ptr, const char *format);
char			*ft_getspe(const char *format, int leng, va_list args, char	*ptr);
int				ft_printf(const char *format, ...);
int				ft_getspelengwidth(const char *format, int leng);
char			*ft_printfspeptr(char *ptr, const char *format, t_spec spec);
int				ft_printflen(char *ptr, const char *format);

#endif
