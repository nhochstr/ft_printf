/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:28:44 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:29:26 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

char *ft_printf_c(t_spec spec, va_list args, char *ptr)
{
	char	*buff;

	if (spec.width > 1)
		buff = ft_malloc_space(spec.width, sizeof(char));
	else
		buff = ft_malloc_space(1, sizeof(char));
	if (spec.flags == '-' && spec.width > 1)
		buff[0] = va_arg(args, int);
	else if (spec.width > 1)
		buff[spec.width - 1] = va_arg(args, int);
	else
		buff[0] = va_arg(args, int);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}