/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:32:56 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:07:18 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_printf_xup(t_spec spec, va_list args, char *ptr)
{
	char	*buff;
	char	*bspace;

	buff = ft_itoxupper(ft_itou(va_arg(args, int)));
	if ((unsigned long)spec.width > ft_strlen(buff))
		bspace = ft_malloc_space(spec.width - ft_strlen(buff), sizeof(char));
	if (spec.precision > (long) ft_strlen(buff) && spec.precision > spec.width)
		bspace = ft_malloc_space(spec.precision - ft_strlen(buff), sizeof(char));
	if (bspace)
		buff = ft_strjoin(bspace, buff);
	if (spec.precision >= 0 && spec.flags == '0')
		spec.flags = '\0';
	if (spec.precision <= 0)
		spec.precision = 1;
	if (spec.precision > (long)ft_strlen(buff))
		buff = ft_strjoin(buff, bspace);
	if (spec.precision > 1 || spec.flags == '0')
		buff = ft_repspczeroxup(buff, spec);
	if (spec.flags == '-')
		buff = ft_switchspace(buff);
	if (ptr)
		ptr = ft_strjoin(ptr, buff);
	else
		ptr = ft_strdup(buff);
	return (ptr);
}
