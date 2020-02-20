/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:59:40 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/20 22:24:15 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

void	ft_setbspace(t_spec spec, char *b, char **bspace)
{
	if ((unsigned long)spec.width > ft_strlen(b) &&
		spec.precision <= spec.width)
		*bspace = ft_malloc_space(spec.width - ft_strlen(b), sizeof(char));
	else if (spec.precision > (long)ft_strlen(b) && spec.precision > spec.width)
		*bspace = ft_malloc_space(spec.precision - ft_strlen(b), sizeof(char));
}

int		ft_setptrdigit(t_spec spec, char **buff, char **bspace, char **ptr)
{
	if (spec.precision == 0 && (*buff)[0] == '0' && (*buff)[1] == '\0' &&
		spec.precision < spec.width)
	{
		free(*buff);
		if (spec.width > 0)
		{
			*bspace = ft_malloc_space(spec.width, sizeof(char));
			*ptr = (*ptr) ? ft_joinprintf(*ptr, *bspace) : ft_strdup(*bspace);
			free(*bspace);
		}
		else
			*ptr = (*ptr) ? ft_joinprintf(*ptr, " ") : ft_strdup(" ");
		return (1);
	}
	if (spec.precision == 0 && (*buff)[0] == '0' && (*buff)[1] == '\0' &&
		spec.precision >= spec.width)
	{
		free(*buff);
		return (1);
	}
	ft_setbspace(spec, *buff, bspace);
	return (0);
}

char	*ft_setbuffp(va_list args)
{
	char			*buff;
	char			*buffptr;
	unsigned long	ptrr;

	buff = va_arg(args, char *);
	if (!buff)
		return (NULL);
	ptrr = (unsigned long)buff;
	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_ptr_addr(ptrr, buffptr, 0);
	buffptr = ft_revtabpointer(buffptr);
	return (buffptr);
}
