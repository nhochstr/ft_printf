/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:48:11 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/20 22:32:18 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

char	*ft_printsleft(t_spec spec, char *copy, char *buff, unsigned int size)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (spec.width == 0)
		spec.width = size;
	if (spec.precision < 0)
		spec.precision = size;
	if (spec.flags == '-')
	{
		while (buff[i[1]] != 0 && i[0]++ < spec.precision && copy[i[2]] != '\0')
			buff[i[1]++] = copy[i[2]++];
	}
	else
	{
		i[1] = ft_strlen(buff) - 1;
		i[2] = ft_strlen(copy) - 1;
		if (i[2] >= spec.precision)
			i[2] = spec.precision - 1;
		while (i[1] >= 0 && i[2] >= 0)
			buff[i[1]--] = copy[i[2]--];
	}
	return (buff);
}

char	*ft_printf_s(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	int		size;
	char	*copy;

	if (!(copy = ft_strdup(va_arg(args, char *))))
		copy = ft_strdup("(null)");
	size = ft_sizeprints(spec, copy);
	buff = ft_malloc_space(size, sizeof(char));
	if (spec.flags == '0')
		buff = ft_repspczeros(buff, size);
	buff = ft_printsleft(spec, copy, buff, size);
	ptr = (ptr) ? ft_joinprintf(ptr, buff) : ft_strdup(buff);
	free(copy);
	if (buff)
		free(buff);
	return (ptr);
}
