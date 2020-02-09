/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:56:13 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/09 13:13:53 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"
//&é
#include <stdio.h>

char	*ft_printf_d_i(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*buffspace;

	buffspace = NULL;
	buff = ft_itoa_long(va_arg(args, int));
	if (spec.precision == 0 && buff[0] == '0' && buff[1] == '\0' && spec.precision < spec.width)
	{
		free(buff);
		if (spec.width > 0)
		{
			buffspace = ft_malloc_space(spec.width, sizeof(char));
			ptr = (ptr) ? ft_strjoins1(ptr, buffspace) : ft_strdup(buffspace);
			free(buffspace);
		}
		else
			ptr = (ptr) ? ft_strjoins1(ptr, " ") : ft_strdup(" ");
		return (ptr);
	}
	if (spec.precision == 0 && buff[0] == '0' && buff[1] == '\0' && spec.precision >= spec.width)
	{
		free(buff);
		return (ptr);
	}
	if ((unsigned long)spec.width > ft_strlen(buff) && spec.precision <= spec.width)
		buffspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long)ft_strlen(buff) && spec.precision > spec.width)
		buffspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
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
