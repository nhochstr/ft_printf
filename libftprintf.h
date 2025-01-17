/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:07:32 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/20 22:34:00 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct			s_spec
{
	char	flags;
	long	width;
	long	precision;
	char	type;
	char	*ptr;
}						t_spec;

int						ft_getleng(int leng);
int						ft_countstring(char const *s, char *str);
unsigned long			ft_strlento(char *str, char c);
char					*ft_strdupchar(char s);
char					*ft_strdup_to(char *s, char c);
char					*ft_strjoinchar(char const *s1, char const s2);
char					*ft_strjoin_to(char const *s1, char const *s2, char c);
char					ft_getflag(const char *format, int leng);
long					ft_getwidth(const char *format, int leng, va_list args);
long					ft_getprecision(const char *format, int leng,
	va_list args);
char					ft_gettype(const char *format, int leng);
int						ft_verifflagnull(t_spec spec);
void					ft_bblank(void *s, size_t n);
char					*ft_malloc_space(size_t count, size_t size);
int						ft_sizeprints(t_spec spec, char *copy);
char					*ft_printf_c(t_spec spec, va_list args, char *ptr);
char					*ft_printsleft(t_spec spec, char *copy, char *buff,
	unsigned int size);
char					*ft_printf_s(t_spec spec, va_list args, char *ptr);
char					*ft_revtabpointer(char *buffptr);
char					*ft_ptr_addr(long addr, char *buffptr, int i);
char					*ft_printf_p(t_spec spec, va_list args, char *ptr);
char					*ft_putzeroflag(char *buff, int neg);
char					*ft_putzeroprec(char *buff, int neg, t_spec spec);
char					*ft_replacespacezero(char *buff, t_spec spec);
char					*ft_switchspace(char *buff);
char					*ft_printf_d_i(t_spec spec, va_list args, char *ptr);
unsigned int			ft_itou(int i);
char					*ft_itoa_long(long n);
char					*ft_printf_u(t_spec spec, va_list args, char *ptr);
char					*ft_converthexa(long nbr, char *buffptr, int i);
char					*ft_converthexaupper(long nbr, char *buffptr, int i);
char					*ft_revtab(char *buffptr);
char					*ft_itox(long nbr);
char					*ft_itoxupper(long nbr);
int						ft_ishexa(int c);
int						ft_ishexaupper(int c);
char					*ft_putzeroflagx(char *buff, int neg);
char					*ft_putzeroprecx(char *buff, int neg, t_spec spec);
char					*ft_putzeroprecxup(char *buff, int neg, t_spec spec);
char					*ft_repspczerox(char *buff, t_spec spec);
char					*ft_repspczeroxup(char *buff, t_spec spec);
char					*ft_printf_x(t_spec spec, va_list args, char *ptr);
char					*ft_printf_xup(t_spec spec, va_list args, char *ptr);
char					*ft_printfspe(t_spec spec, va_list args, char *ptr,
	const char *format);
char					*ft_getspe(const char *format, int leng, va_list args,
	char	*ptr);
int						ft_printf(const char *format, ...);
int						ft_getspelengwidth(const char *format, int leng);
char					*ft_printfspeptr(char *ptr, const char *format,
	t_spec spec);
int						ft_printflen(char *ptr, const char *format);
char					*ft_strjoins2(char const *s1, char const *s2);
char					*ft_strjoins1(char const *s1, char const *s2);
int						ft_getnbr0(int i);
char					*ft_joinprintf(char const *s1, char const *s2);
char					*ft_joinprintfnull(char const *s1, char const *s2);
size_t					ft_strlenprintf(const char *s);
char					*ft_dupnull(const char *s);
char					*ft_joinprintf_to(char const *s1, char const *s2,
	char c);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
long					ft_countnbr(long nbr);
int						ft_isdigit(int c);
void					ft_putchar_fd(char c, int fd);
char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *s);
void					ft_bzero(void *s, size_t n);
size_t					ft_strlennull(const char *s);
int						ft_joinwithoutmalloczero(char *s1, const char *s2);
int						ft_joinwithoutmallocij(char *s1, const char *s2, int i,
	int j);
int						ft_joinwithoutmalloci(char *s1, const char *s2, int i);
void					ft_setbspace(t_spec spec, char *b, char **bspace);
int						ft_setptrdigit(t_spec spec, char **buff, char **bspace,
	char **ptr);
char					*ft_repspczerop(char *buff);
char					*ft_setbuffp(va_list args);
char					*ft_ptr_addr(long addr, char *buffptr, int i);
char					*ft_repspczeros(char *buff, int size);

#endif
