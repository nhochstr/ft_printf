/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/26 16:00:35 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int	ft_getleng(int leng)
{
	static int i = 0;

	if (leng > 0)
		i = leng;
	return (i);
}

int	ft_countstring(char const *s, char *str)
{
	int	i;
	int	j;
	int nbr;

	i = 0;
	nbr = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == str[j])
		{
			j++;
			if (str[j] == 0)
			{
				nbr++;
				j = 0;
			}
		}
		else
			j = 0;
		i++;
	}
	return (nbr);
}

unsigned long	ft_strlento(char *str, char c)
{
	unsigned long	i;

	i = 0;
	while (*str != '\0' && *str != c)
	{
		i++;
		str = str + 1;
	}
	return (i);
}

char	*ft_strdupchar(char s)
{
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) + 1)))
		return (NULL);
	ptr[0] = s;
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_strdup_to(char *s, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc(ft_strlento((char*)s, '%') * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoinchar(char const *s1, char const s2)
{
	char	*ptr;
	int		i;
	int		leng;

	leng = ft_strlen((char*)s1) + 1;
	i = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;

	ptr[i++] = s2;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_to(char const *s1, char const *s2, char c)
{
	char	*ptr;
	int		i;
	int		leng;

	leng = ft_strlen((char*)s1) + ft_strlento((char*)s2, c);
	i = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2 != c && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}


char	ft_getflag(const char *format, int leng)
{
	if (format[leng] == '-' || format[leng] == '0')
		return (format[leng]);
	return (0);
}

long	ft_getwidth(const char *format, int leng, va_list args)
{
	if (format[leng] == '*')
	{
		return (va_arg(args, int));
	}
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}

long	ft_getprecision(const char *format, int leng, va_list args)
{
	if (format[leng] == '.')
		leng++;
	else
		return (-1);
	if (format[leng] == '*')
	{
		return (va_arg(args, int));
	}
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (-1);
}

char ft_gettype(const char *format, int leng)
{
	if (format[leng] == 'c')
		return ('c');
	if (format[leng] == 's')
		return ('s');
	if (format[leng] == 'p')
		return ('p');
	if (format[leng] == 'd')
		return ('d');
	if (format[leng] == 'i')
		return ('i');
	if (format[leng] == 'u')
		return ('u');
	if (format[leng] == 'x')
		return ('x');
	if (format[leng] == 'X')
		return ('X');
	return (0);
}

int ft_verifflagnull(t_spec spec)
{
	if (spec.flags != '0')
		return (1);
	if (spec.type == 'c' || spec.type == 'p' || spec.type == 's')
		return (0);
	return (1);
}

void	ft_bblank(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = ' ';
}

char	*ft_malloc_space(size_t count, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(count * size + 1)))
		return (NULL);
	ft_bblank(ptr, count * size);
	ptr[count] = 0;
	return (ptr);
}

int	ft_sizeprints(t_spec spec, char *copy)
{
	int	size;
	int				leng;

	leng = ft_strlen(copy);
	size = leng;
	if (spec.precision >= 0 && leng > spec.precision)
		size = spec.precision;
	if (spec.width > size)
		size = spec.width;
	return (size);
}

char *ft_printf_c(t_spec spec, va_list args, char *ptr)
{
	char	*buff;

	if (spec.width > 1)
		buff = ft_malloc_space(spec.width, sizeof(char));
	else
		buff = ft_malloc_space(1, sizeof(char));
	if (spec.flags == '-' && spec.width > 1)
		buff[0] = va_arg(args, int);
	else if (spec.width > 1)
		buff[spec.width - 1] = va_arg(args, int);
	else
		buff[0] = va_arg(args, int);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}

char	*ft_printsleft(t_spec spec, char *copy, char *buff, unsigned int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (spec.width == 0)
		spec.width = size;
	if (spec.precision < 0)
		spec.precision = size;
	if (spec.flags == '-')
	{
		while (buff[j] != 0 && i++ < spec.precision && copy[k] != '\0')
			buff[j++] = copy[k++];
	}
	else
	{
		j = ft_strlen(buff) - 1;
		k = ft_strlen(copy) - 1;
		if (k >= spec.precision)
			k = spec.precision - 1;
		while (j >= 0 && k >= 0)
			buff[j--] = copy[k--];
	}
	return (buff);
}

char	*ft_printf_s(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	int		size;
	char	*copy;

	copy = ft_strdup(va_arg(args, char *));
	size = ft_sizeprints(spec, copy);
	buff = ft_malloc_space(size, sizeof(char));
	buff = ft_printsleft(spec, copy, buff, size);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}

char	*ft_revtabpointer(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
	buffptr = ft_strjoin(buffptr, "x0");
	leng = ft_strlen(buffptr) - 1;

	while(i <= leng)
	{
		c = buffptr[i];
		buffptr[i] = buffptr[leng];
		buffptr[leng] = c;
		i++;
		leng--;
	}
	return (buffptr);
}

char	*ptr_addr(long addr, char *buffptr, int i)
{
	if (addr >= 16)
		buffptr = ptr_addr(addr / 16, buffptr, i + 1);
	addr = addr % 16 + 48;
	if (addr > 57)
		addr += 39;
	buffptr[i] = addr;
	return (buffptr);
}

char	*ft_printf_p(t_spec spec, va_list args, char *ptr)
{
	char			*buff;
	unsigned long	ptrr;
	char			*buffptr;
	char			*buffspace;

	buff = va_arg(args, char *);
	ptrr = (unsigned long)buff;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ptr_addr(ptrr, buffptr, 0);
	buffptr = ft_revtabpointer(buffptr);
	if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffspace = ft_malloc_space(spec.width - ft_strlen(buffptr), sizeof(char));
	if (ft_strlen(buffptr) < (unsigned long)spec.width && spec.flags == '-')
		buffptr = ft_strjoin(buffptr, buffspace);
	else if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffptr = ft_strjoin(buffspace, buffptr);
	if (ptr)
		ptr = ft_strjoin(ptr, buffptr);
	else
		ptr = ft_strdup(buffptr);
	return (ptr);
}

char	*ft_putzeroflag(char *buff, int neg)
{
	long i;

	i = 0;
	if (neg == 1)
	{
		i = 1;
		buff[0] = '-';
	}
	while (buff[i] == ' ' || buff[i] == '-')
		buff[i++] = '0';
	return (buff);
}

char	*ft_putzeroprec(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_isdigit(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoin("-", buff);
	if (size > 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}

char	*ft_replacespacezero(char *buff, t_spec spec)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (buff[i] == ' ')
		i++;
	if (buff[i] == '-')
		neg = 1;
	if (spec.flags == '0')
		buff = ft_putzeroflag(buff, neg);
	else
		buff = ft_putzeroprec(buff, neg, spec);
	return (buff);
}

char	*ft_switchspace(char *buff)
{
	char			*ptr;
	unsigned long	i;
	unsigned long	j;

	ptr = ft_strdup(buff);
	i = 0;
	j = 0;
	while (buff[i] == ' ')
		i++;
	while (buff[i] != '\0')
		ptr[j++] = buff[i++];
	while (ptr[j] != '\0')
		ptr[j++] = ' ';
	return (ptr);
}

char	*ft_itoa_long(long n)
{
	char	*str;
	long	nb;
	long	i;

	nb = n;
	i = ft_countnbr(nb);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}

char	*ft_printf_d_i(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*buffspace;

	buff = ft_itoa_long(va_arg(args, int));
	if ((unsigned long)spec.width > ft_strlen(buff))
		buffspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		buffspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (buffspace)
		buff = ft_strjoin(buffspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, buffspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_replacespacezero(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}

char	*ft_printfspe(t_spec spec, va_list args, char *ptr, const char *format)
{
	if (spec.type == 0)
	{
		if (ptr)
			ptr = ft_strjoinchar(ptr, (char)format[ft_getleng(0)]);
		else
			ptr = ft_strdupchar((char)format[ft_getleng(0)]);
		ft_getleng(ft_getleng(0) + 1);
	}
	if (ft_verifflagnull(spec) == 0)
		return (NULL);
	if (spec.type == 'c')
		ptr = ft_printf_c(spec, args, ptr);
	if (spec.type == 's')
	 	ptr = ft_printf_s(spec, args, ptr);
	if (spec.type == 'p')
		ptr = ft_printf_p(spec, args, ptr);
	if (spec.type == 'd')
		ptr = ft_printf_d_i(spec, args, ptr);
	if (spec.type == 'i')
		ptr = ft_printf_d_i(spec, args, ptr);
	// if (spec.type == 'u')
	// 	ptr = ft_printf_u(spec, args, ptr);
	// if (spec.type == 'x')
	// 	ptr = ft_printf_x(spec, args, ptr);
	// if (spec.type == 'X')
	// 	ptr = ft_printf_X(spec, args, ptr);
	return (ptr);
}

char	*ft_getspe(const char *format, int leng, va_list args, char	*ptr)
{
	t_spec spec;

	if (format[leng] == '%')
		leng++;
	spec.flags = ft_getflag(format, leng);
	if (spec.flags != 0)
		leng++;
	spec.width = ft_getwidth(format, leng, args);
	if (spec.width != 0)
	{
		while (ft_isdigit(format[leng]) == 1 )
			leng++;
		if (format[leng] == '*')
			leng++;
	}
	spec.precision = ft_getprecision(format, leng, args);
	if (spec.precision != -1)
	{
		leng++;
		while (ft_isdigit(format[leng]) == 1 )
			leng++;
		if (format[leng] == '*')
			leng++;
	}
	spec.type = ft_gettype(format, leng);
	if (spec.type != 0)
		leng++;
	ft_getleng(leng);
	return (ft_printfspe(spec, args, ptr, format));
}

int ft_printf(const char *format, ...)
{
	va_list args;
	char	*ptr;
	int		leng;

	leng = 0;
	ptr = NULL;
	
	va_start(args, format);
		while (format[leng] != '\0')
		{
			if (ptr)
				ptr = ft_strjoin_to(ptr, &format[leng], '%');
			else
				ptr = ft_strdup_to((char *)&format[leng], '%');
			leng = leng + ft_strlento((char *)&format[leng], '%');
			if (format[leng] != '\0')
			{
				ptr = ft_getspe(format, leng, args, ptr);
				leng = ft_getleng(0);
			}
		}
	va_end(args);
	ft_putstr_fd(ptr, 1);
	return leng;
}

// gcc -Wall -Wextra -Werror -L./ -lft -fsanitize=address main.c  && ./a.out
int main()
{
	int j = printf("Bonjour%5c + %*.*s - %-13p - %-10.7d$\n", 'N', 10, 5, "Lauraa", "héhé", -118218);
	int i = ft_printf("Bonjour%5c + %*.*s - %-13p - %-10.7i$\n", 'N', 10, 5, "Lauraa", "héhé", -118218);
	printf("%d - %d\n", j, i);
	return 0;
}