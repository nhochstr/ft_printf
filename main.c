/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/09 14:11:29 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"

/*
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
	char			*bspace;

	buff = va_arg(args, char *);
	ptrr = (unsigned long)buff;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ptr_addr(ptrr, buffptr, 0);
	buffptr = ft_revtabpointer(buffptr);
	if (ft_strlen(buffptr) < (unsigned long)spec.width)
		bspace = ft_malloc_space(spec.width - ft_strlen(buffptr), sizeof(char));
	if (ft_strlen(buffptr) < (unsigned long)spec.width && spec.flags == '-')
		buffptr = ft_strjoin(buffptr, bspace);
	else if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffptr = ft_strjoin(bspace, buffptr);
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

char	*ft_printf_d_i(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	buff = ft_itoa(va_arg(args, int));
	if ((unsigned long)spec.width > ft_strlen(buff))
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoin(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, bspace);
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

unsigned int	ft_itou(int i)
{
	unsigned int	u;

	if (i < 0)
		u = 2147483647 + 2147483649 + i;
	else
		u = i;
	return (u);
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

char	*ft_printf_u(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	buff = ft_itoa_long(ft_itou(va_arg(args, int)));
	if ((unsigned long)spec.width > ft_strlen(buff))
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoin(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, bspace);
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

char	*ft_converthexa(long nbr, char *buffptr, int i)
{
	if (nbr >= 16)
		buffptr = ft_converthexa(nbr / 16, buffptr, i + 1);
	nbr = nbr % 16 + 48;
	if (nbr > 57)
		nbr += 39;
	buffptr[i] = nbr;
	return (buffptr);
}

char	*ft_converthexaupper(long nbr, char *buffptr, int i)
{
	if (nbr >= 16)
		buffptr = ft_converthexaupper(nbr / 16, buffptr, i + 1);
	nbr = nbr % 16 + 48;
	if (nbr > 57)
		nbr += 7;
	buffptr[i] = nbr;
	return (buffptr);
}

char	*ft_revtab(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
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

char	*ft_itox(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexa(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}

char	*ft_itoxupper(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexaupper(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}

int	ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

int	ft_ishexaupper(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

char	*ft_putzeroflagx(char *buff, int neg)
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

char	*ft_putzeroprecx(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_ishexa(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoin("-", buff);
	if (size > 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}

char	*ft_putzeroprecxup(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_ishexaupper(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoin("-", buff);
	if (size > 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}

char	*ft_repspczerox(char *buff, t_spec spec)
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
		buff = ft_putzeroflagx(buff, neg);
	else
		buff = ft_putzeroprecx(buff, neg, spec);
	return (buff);
}

char	*ft_repspczeroxup(char *buff, t_spec spec)
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
		buff = ft_putzeroflagx(buff, neg);
	else
		buff = ft_putzeroprecxup(buff, neg, spec);
	return (buff);
}

char	*ft_printf_x(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	buff = ft_itox(ft_itou(va_arg(args, int)));
	if ((unsigned long)spec.width > ft_strlen(buff))
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoin(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, bspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_repspczerox(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}

char	*ft_printf_xup(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;
	buff = ft_itoxupper(ft_itou(va_arg(args, int)));
	if ((unsigned long)spec.width > ft_strlen(buff))
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoin(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, bspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_repspczeroxup(buff, spec);
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
	if (spec.type == 'u')
	 	ptr = ft_printf_u(spec, args, ptr);
	if (spec.type == 'x')
	 	ptr = ft_printf_x(spec, args, ptr);
	if (spec.type == 'X')
	 	ptr = ft_printf_xup(spec, args, ptr);
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
	return (ft_strlen(ptr));
}
*/
//  gcc -Wall -Wextra -Werror -L./libft -lft -L. -lftprintf -g -fsanitize=address main.c  && ./a.out

// tester si % est le premier char
// tester si % est le dernier char
// tester sans %
int main()
{
	int y = 0;
	int z = 0;
	/*int i = 0;
	int j = 0;
	j = printf("Bonjour%5c + %*.*s - %-13p - %010d - %-20.12u - %-10.9x - %-10.9X$\n", 'N', 10, 5, "Lauraa", "héhé", -118218, -1, -1, -1234332);
	i = ft_printf("Bonjour%5c + %*.*s - %-13p - %010i - %-20.12u - %-10.9x - %-10.9X$\n", 'N', 10, 5, "Lauraa", "héhé", -118218, -1, -1, -1234332);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s\n", "Hahaha");
	i = ft_printf("%s\n", "Hahaha");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("Hello World%%\n");
	i = ft_printf("Hello World%%\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("Black Lightning\n");
	i = ft_printf("Black Lightning\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("");
	i = ft_printf("");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.i$\n", 44);
	i = ft_printf("%.i$\n", 44);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0i$\n", 0);
	i = ft_printf("%.0i$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.d$\n", 0);
	i = ft_printf("%.d$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%d$\n", 0);
	i = ft_printf("%d$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.u$\n", 0);
	i = ft_printf("%.u$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0x$\n", 0);
	i = ft_printf("%.0x$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0X$\n", 0);
	i = ft_printf("%.0X$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%c", '\0');
	i = ft_printf("%c", '\0');
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%---4c\n", 'a');
	i = ft_printf("%---4c\n", 'a');
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s\n", NULL);
	i = ft_printf("%s\n", NULL);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s", "");
	i = ft_printf("%s", "");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.2s", NULL);
	i = ft_printf("%.2s", NULL);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%00-12.15m012$\n");
	i = ft_printf("%00-12.15m012$\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("hello ca%----4c$ %1c va %-6c ??\n", 'a', '\n', 0);
	i = ft_printf("hello ca%----4c$ %1c va %-6c ??\n", 'a', '\n', 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 23: %1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.ld, %1.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	i = ft_printf("test 23: %1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 12: %0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.ld, %0.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	i = ft_printf("test 12: %0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*ld, %*d\n", -4, 8, -4, -12, -4, 123456789, -4, 0, -4, -12345678, -4, 'a', -4, -2147483648, -4, 2147483647);
	i = ft_printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", -4, 8, -4, -12, -4, 123456789, -4, 0, -4, -12345678, -4, 'a', -4, -2147483648, -4, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*ld, %*d\n", 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483648, 0, 2147483647);
	i = ft_printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483648, 0, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*ld, %*.*d\n", -2, 0, 8, -2, 0, -12, -2, 0, 123456789, -2, 0, 0, -2, 0, -12345678, -2, 0, 'a', -2, 0, -2147483648, -2, 0, 2147483647);
	i = ft_printf("test 34: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", -2, 0, 8, -2, 0, -12, -2, 0, 123456789, -2, 0, 0, -2, 0, -12345678, -2, 0, 'a', -2, 0, -2147483648, -2, 0, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 211: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*ld, %*.*d\n", 4, 3, 8, 4, 3, -12, 4, 3, 123456789, 4, 3, 0, 4, 3, -12345678, 4, 3, 'a', 4, 3, -2147483648, 4, 3, 2147483647);
	i = ft_printf("test 211: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", 4, 3, 8, 4, 3, -12, 4, 3, 123456789, 4, 3, 0, 4, 3, -12345678, 4, 3, 'a', 4, 3, -2147483648, 4, 3, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	*/
	/*
	int		a = 2;
	int		b = 3;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	z = printf("test 211: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	y = ft_printf("test 211: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("test 444: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	y = ft_printf("test 444: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -1, 'a', 0, 'a', 0, 'a', 0, 'a');
	y = ft_printf("f test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -1, 'a', 0, 'a', 0, 'a', 0, 'a');
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	//z = printf("r test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	z = printf("r test 510: %c$\n", 0);
	y = ft_printf("f test 510: %c$\n", 0);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: %ca%1igr%%%-1c%-20.3X%%%*.4X\n", '\0', 2147483647, 'k', -2147483647, 5, 0);
	y = ft_printf("f test 510: %ca%1igr%%%-1c%-20.3X%%%*.4X\n", '\0', 2147483647, 'k', -2147483647, 5, 0);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");

	%XCPc48t T3CuJ%16cs3WQOAo0%-*.0i%.3iN", -2147483647, '\0', 8, 0, 2147483647
	
	z = printf("r test 510: %XCPc48t T3CuJ%16cs3WQOAo0%-*.0i%.3iN\n", -2147483647, '\0', 8, 0, 2147483647);
	y = ft_printf("f test 510: %XCPc48t T3CuJ%16cs3WQOAo0%-*.0i%.3iN\n", -2147483647, '\0', 8, 0, 2147483647);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");

	TH%%%u%c%4.0xNDjWuuN%-*c", -361203380, '\0', 0, 5, 'B'
	*/
	z = printf("r test 510: TH%%%u%c%4.0xNDjWuuN%-*c\n", -361203380, '\0', 0, 5, 'B');
	y = ft_printf("f test 510: TH%%%u%c%4.0xNDjWuuN%-*c\n", -361203380, '\0', 0, 5, 'B');
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	return 0;
}
