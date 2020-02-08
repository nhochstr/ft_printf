/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:51:12 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 17:10:13 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_printf_p(t_spec spec, va_list args, char *ptr)
{
	char			*buff;
	unsigned long	ptrr;
	char			*buffptr;
	char			*buffspace;

	buffspace = NULL;
	buff = va_arg(args, char *);
	ptrr = (unsigned long)buff;
	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_ptr_addr(ptrr, buffptr, 0);
	buffptr = ft_revtabpointer(buffptr);
	if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffspace = ft_malloc_space(spec.width - ft_strlen(buffptr), sizeof(char));
	if (ft_strlen(buffptr) < (unsigned long)spec.width && spec.flags == '-')
		buffptr = ft_strjoins1(buffptr, buffspace);
	else if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffptr = ft_strjoins2(buffspace, buffptr);
	if (ptr)
		ptr = ft_joinprintf(ptr, buffptr);
	else
		ptr = ft_strdup(buffptr);
	if (buffspace)
		free(buffspace);
	free(buffptr);
	return (ptr);
}
