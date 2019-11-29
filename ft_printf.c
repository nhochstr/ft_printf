/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:46:35 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"

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
