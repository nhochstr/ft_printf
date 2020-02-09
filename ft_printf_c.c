/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:28:44 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/09 13:41:06 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"
//
#include <stdio.h>

char *ft_printf_c(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	vchar;

	buff = NULL;
	if (spec.width > 1)
		buff = ft_malloc_space(spec.width, sizeof(char));
	else
		buff = ft_malloc_space(1, sizeof(char));
	vchar = va_arg(args, int);
	if (spec.flags == '-' && spec.width > 1)
		buff[0] = vchar;
	else if (spec.width > 1)
		buff[spec.width - 1] = vchar;
	else
		buff[0] = vchar;
	if (vchar == '\0')
	{
		ptr = (ptr) ? ft_joinprintfnull(ptr, buff) : ft_dupnull(buff);
		ft_getnbr0(1);
	}
	else
		ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	if (buff)
		free(buff);
	return (ptr);
}
