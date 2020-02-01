/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:48:11 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/01 11:28:34 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_printf_s(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	int		size;
	char	*copy;

	if (!(copy = ft_strdup(va_arg(args, char *))))
		copy = ft_strdup("(null)");
	size = ft_sizeprints(spec, copy);
	buff = ft_malloc_space(size, sizeof(char));
	buff = ft_printsleft(spec, copy, buff, size);
	ptr = (ptr) ? ft_strjoins1(ptr, buff) : ft_strdup(buff);
	free (copy);
	if (buff)
		free (buff);
	return (ptr);
}
