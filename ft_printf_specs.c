/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:34:57 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/17 19:58:04 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_getspelengwidth(const char *format, int leng)
{
	while (ft_isdigit(format[leng]) == 1)
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
		while (ft_isdigit(format[leng]) == 1)
			leng++;
		if (format[leng] == '*')
			leng++;
	}
	return (leng);
}

char	*ft_getspe(const char *format, int leng, va_list args, char *ptr)
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

char	*ft_printfspeptr(char *ptr, const char *format, t_spec spec)
{
	char	*buff;
	int		leng;

	leng = ft_getleng(0);
	if (format[leng] == '\0')
		ptr = (ptr) ? ft_joinprintf(ptr, "") : ft_strdup("");
	if (format[leng] == '\0')
		return (ptr);
	if (spec.width > 1)
		buff = ft_malloc_space(spec.width, sizeof(char));
	else
		buff = ft_malloc_space(1, sizeof(char));
	if (!buff)
		return (NULL);
	if (spec.flags == '-' && spec.width > 1)
		buff[0] = format[leng];
	else if (spec.width > 1)
		buff[spec.width - 1] = format[leng];
	else
		buff[0] = format[leng];
	if (spec.flags == '0')
		buff = ft_replacespacezero(buff, spec);
	ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	free(buff);
	return (ptr);
}

char	*ft_printfspe(t_spec spec, va_list args, char *ptr, const char *format)
{
	if (spec.type == 0)
	{
		ptr = ft_printfspeptr(ptr, format, spec);
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
