/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:34:57 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/30 00:24:27 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int		ft_getspelengwidth(const char *format, int leng)
{
	while (ft_isdigit(format[leng]) == 1 )
		leng++;
	if (format[leng] == '*')
		leng++;
	return (leng);
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
		leng = ft_getspelengwidth(format, leng);
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
