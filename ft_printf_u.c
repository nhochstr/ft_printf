/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:21:35 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/09 14:10:43 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"
//
#include <stdio.h>

char	*ft_printf_u(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	bspace = NULL;
	buff = ft_itoa_long(ft_itou(va_arg(args, int)));
	if (spec.precision == 0 && buff[0] == '0' && buff[1] == '\0' && spec.precision < spec.width)
	{
		free(buff);
		if (spec.width > 0)
		{
			bspace = ft_malloc_space(spec.width, sizeof(char));
			ptr = (ptr) ? ft_joinprintf(ptr, bspace) : ft_strdup(bspace);
			free(bspace);
		}
		else
			ptr = (ptr) ? ft_joinprintf(ptr, " ") : ft_strdup(" ");
		return (ptr);
	}
	if (spec.precision == 0 && buff[0] == '0' && buff[1] == '\0' && spec.precision >= spec.width)
	{
		free(buff);
		return (ptr);
	}
	if ((unsigned long)spec.width > ft_strlen(buff) && spec.precision <= spec.width)
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	else if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoins2(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoins1(buff, bspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_replacespacezero(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	free(buff);
	if (bspace)
		free(bspace);
	return (ptr);
}
