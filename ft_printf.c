/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:57:02 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft/libft.h"

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