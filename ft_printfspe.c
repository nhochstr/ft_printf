/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfspe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:33:31 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:11:42 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printfspeptr(char *ptr, const char *format)
{
	if (ptr)
		ptr = ft_strjoinchar(ptr, (char)format[ft_getleng(0)]);
	else
		ptr = ft_strdupchar((char)format[ft_getleng(0)]);
	return (ptr);
}

char	*ft_printfspe(t_spec spec, va_list args, char *ptr, const char *format)
{
	if (spec.type == 0)
	{
		ptr = ft_printfspeptr(ptr, format);
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