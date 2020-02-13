/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:20:30 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:25:47 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_getflag(const char *format, int leng)
{
	char c;

	c = 0;
	while (format[leng] == '-' || format[leng] == '0')
	{
		if (format[leng] == '-')
			return (format[leng]);
		if (format[leng] == '0')
			c = '0';
		leng++;
	}
	return (c);
}

long	ft_getprecision(const char *format, int leng, va_list args)
{
	if (format[leng] == '.')
		leng++;
	else
		return (-1);
	if (format[leng] == '*')
		return (va_arg(args, int));
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}

char	ft_gettype(const char *format, int leng)
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

long	ft_getwidth(const char *format, int leng, va_list args)
{
	if (format[leng] == '*')
		return (va_arg(args, int));
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}
