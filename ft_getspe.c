/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:34:57 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 07:49:33 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getspelengwidth(const char *format, int leng)
{
	while (ft_isdigit(format[leng]) == 1 )
		leng++;
	if (format[leng] == '*')
		leng++;
	return (leng);
}

int		ft_getspelengprec(const char *format, int leng)
{
	if (format[leng] == '.')
	{
		leng++;
		while (ft_isdigit(format[leng]) == 1 )
			leng++;
		if (format[leng] == '*')
			leng++;
	}
	return(leng);
}

char	*ft_getspe(const char *format, int leng, va_list args, char	*ptr)
{
	t_spec	spec;
	char	*vprintf;

	if (format[leng] == '%')
		leng++;
	while (format[leng] == ' ')
		leng++;
	spec.flags = ft_getflag(format, leng);
	while (spec.flags != 0 && (format[leng] == '-' || format[leng] == '0'))
		leng++;
	spec.width = ft_getwidth(format, leng, args);
	if (spec.width < 0)
	{
		spec.flags = '-';
		spec.width = -spec.width;
	}
	leng = ft_getspelengwidth(format, leng);
	spec.precision = ft_getprecision(format, leng, args);
	leng = ft_getspelengprec(format, leng);
	spec.type = ft_gettype(format, leng);
	if (spec.type != 0)
		leng++;
	ft_getleng(leng);
	vprintf = ft_printfspe(spec, args, ptr, format);
	return (vprintf);
}
