/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:51:12 by nhochstr          #+#    #+#             */
/*   Updated: 2019/12/12 13:33:37 by nhochstr         ###   ########.fr       */
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

	buff = va_arg(args, char *);
	ptrr = (unsigned long)buff;
	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_ptr_addr(ptrr, buffptr, 0);
	buffptr = ft_revtabpointer(buffptr);
	if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffspace = ft_malloc_space(spec.width - ft_strlen(buffptr), sizeof(char));
	if (ft_strlen(buffptr) < (unsigned long)spec.width && spec.flags == '-')
		buffptr = ft_strjoin(buffptr, buffspace);
	else if (ft_strlen(buffptr) < (unsigned long)spec.width)
		buffptr = ft_strjoin(buffspace, buffptr);
	if (ptr)
		ptr = ft_strjoin(ptr, buffptr);
	else
		ptr = ft_strdup(buffptr);
	return (ptr);
}
