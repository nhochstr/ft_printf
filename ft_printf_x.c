/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:30:40 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:02:05 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

char	*ft_printf_x(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	bspace = NULL;
	buff = ft_itox(ft_itou(va_arg(args, int)));
	if (ft_setptrdigit(spec, &buff, &bspace, &ptr) == 1)
		return (ptr);
	if (bspace)
		buff = ft_strjoins2(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoins1(buff, bspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_repspczerox(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	free(buff);
	if (bspace)
		free(bspace);
	return (ptr);
}
