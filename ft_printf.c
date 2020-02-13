/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 08:40:41 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

void	ft_putprintf_fd(char *s, int fd)
{
	long		i;
	long		j;

	j = 0;
	i = 0;
	if (s)
	{
		while ((j < ft_getnbr0(0) && ft_getnbr0(0) != 0))
		{
			if (s[i] == '\0')
				j++;
			ft_putchar_fd(s[i++], fd);
		}
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	}
}

int		ft_setptr(char **ptr, const char *format, int leng)
{
	if (*ptr)
		*ptr = ft_joinprintf_to(*ptr, &format[leng], '%');
	else
		*ptr = ft_strdup_to((char *)&format[leng], '%');
	leng = leng + ft_strlento((char *)&format[leng], '%');
	return (leng);
}

int 	ft_printf(const char *format, ...)
{
	va_list args;
	char	*ptr;
	int		leng;
	int		size;

	leng = 0;
	if (format[leng] == '\0')
		return (0);
	ptr = NULL;
	va_start(args, format);
	while (format[leng] != '\0')
	{
		leng = ft_setptr(&ptr, format, leng);
		if (format[leng] != '\0')
		{
			ptr = ft_getspe(format, leng, args, ptr);
			leng = ft_getleng(0);
		}
	}
	va_end(args);
	ft_putprintf_fd(ptr, 1);
	size = ft_strlenprintf(ptr);
	ft_getnbr0(-1);
	free(ptr);
	return (size);
}
