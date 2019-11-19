/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/19 15:37:35 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

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

char	ft_getflag(const char *format, int leng)
{
	if (format[leng] == '-' || format[leng] == '0')
		return (format[leng]);
	return (0);
}

unsigned int	ft_getwidth(const char *format, int leng, va_list args)
{
	if (format[leng] == '*')
	{
		return (va_arg(args, int));
	}
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}

unsigned int	ft_getprecision(const char *format, int leng, va_list args)
{
	if (format[leng] == '.')
		leng++;
	else
		return (0);
	if (format[leng] == '*')
	{
		return (va_arg(args, int));
	}
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}

char *ft_gettype(const char *format, int leng)
{
	if (format[leng] == 'c')
		return ("char");
	if (format[leng] == 's')
		return ("string");
	if (format[leng] == 'p')
		return ("pointer");
	if (format[leng] == 'd')
		return ("decimal");
	if (format[leng] == 'i')
		return ("int");
	if (format[leng] == 'u')
		return ("unsigned int");
	if (format[leng] == 'x')
		return ("hexa");
	if (format[leng] == 'X')
		return ("hexaup");
	return (0);
}

int	ft_getspe(const char *format, int leng, va_list args)
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
	if (spec.precision != 0)
	{
		leng++;
		while (ft_isdigit(format[leng]) == 1 )
			leng++;
		if (format[leng] == '*')
			leng++;
	}
	spec.type = ft_gettype(format, leng);
	if (spec.type != 0)
	{
		leng++;
	}
	else
		return (-1);

	printf("char: %c\n", format[leng]);
	printf("flag: %c\n", spec.flags);
	printf("width: %d\n", spec.width);
	printf("precision: %d\n", spec.precision);
	printf("type: %s\n", spec.type);

	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	char	*ptr;
	int		leng;

	leng = 0;
	
	va_start(args, format);
			ptr = ft_strdup_to((char *)format, '%');
			leng = ft_strlento((char *)format + leng, '%');
			if (format[leng] != '\0')
				ft_getspe(format, leng, args);
	va_end(args);
	ft_putstr_fd(ptr, 1);
	return leng;
}

// gcc -Wall -Wextra -Werror -L./ -lft -fsanitize=address main.c  && ./a.out
int main()
{
	printf("%.*s - %s - %s\n", 3, "haha", "hihi", "hoho");
	printf("%s - %s - %%s\n", "haha", "hihi");
	int i = ft_printf("Bonjour%01234.*s%d%%d%%\n", 2, "hello", "hi");
	printf("\ni = %d\n", i);
	return 0;
}