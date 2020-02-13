/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:56:13 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:01:45 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

char	*ft_printf_d_i(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*buffspace;

	buffspace = NULL;
	buff = ft_itoa_long(va_arg(args, int));
	if (ft_setptrdigit(spec, &buff, &buffspace, &ptr) == 1)
		return (ptr);
	if (buffspace)
		buff = ft_strjoins2(buffspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff) && buffspace)
		buff = ft_strjoins1(buff, buffspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_replacespacezero(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	free(buff);
	if (buffspace)
		free(buffspace);
	return (ptr);
}
