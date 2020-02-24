/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:51:12 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/24 12:12:56 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

char	*ft_ptr_addr(long addr, char *buffptr, int i)
{
	if (addr >= 16)
		buffptr = ft_ptr_addr(addr / 16, buffptr, i + 1);
	addr = addr % 16 + 48;
	if (addr > 57)
		addr += 39;
	buffptr[i] = addr;
	return (buffptr);
}

char	*ft_mallocp(t_spec spec, int leng, int i)
{
	if (i == 0)
		return(ft_malloc_space((spec.precision - leng), sizeof(char)));
	if (i == 1)
		return(ft_malloc_space((spec.precision - (2 + leng)), sizeof(char)));
	return (0);
}

char	*ft_setspacepp(t_spec spec, char *buff)
{
	char	*bs;
	int		leng;
	char	*bptr;

	bptr = NULL;
	leng = (buff) ? ft_strlen(buff) : 0;
	bs = ft_strdup("0x");
	if (spec.precision > 0 && spec.precision > leng && buff)
		bptr = ft_mallocp(spec, leng, 0);
	if (spec.precision > 0 && !buff)
		bptr = ft_malloc_space(spec.precision, sizeof(char));
	if (spec.precision == -1 && spec.flags == '0' && spec.width > (leng + 2) &&
		buff)
		bptr = ft_mallocp(spec, leng, 1);
	if (spec.precision == -1 && spec.flags == '0' && (spec.width - 2) > 0 &&
		!buff)
		bptr = ft_malloc_space((spec.width - 2), sizeof(char));
	bs = (bptr) ? ft_strjoins1(bs,bptr) : bs;
	bs = (spec.precision != -1 || spec.flags == '0') ? ft_repspczerop(bs) : bs;
	bs = (buff) ? ft_strjoins1(bs, buff) : bs;
	(buff) ? free(buff) : (0);
	(bptr) ? free(bptr) : (0);
	return (bs);
}

char	*ft_setspacepw(t_spec spec, char *buff)
{
	char	*bspace;
	int		leng;

	bspace = NULL;
	leng = ft_strlen(buff);
	if ((spec.flags != '0' && spec.precision > 0 && spec.width <= leng) ||
		(spec.flags == '0' && spec.precision == -1))
		return (buff);
	if (leng == 2 && spec.precision == -1)
	{
		buff = ft_strjoins1(buff, "0");
		leng++;
	}
	if (spec.width > leng)
		bspace = ft_malloc_space((spec.width - leng), sizeof(char));
	bspace = (bspace) ? ft_strjoins1(bspace, buff) : ft_strdup(buff);
	if (spec.flags == '-' && bspace)
		bspace = ft_switchspace(bspace);
	free(buff);
	return (bspace);
}

char	*ft_printf_p(t_spec spec, va_list args, char *ptr)
{
	char			*buffptr;

	buffptr = ft_setbuffp(args);
	buffptr = ft_setspacepp(spec, buffptr);
	buffptr = ft_setspacepw(spec, buffptr);
	ptr = (ptr) ? ft_joinprintf(ptr, buffptr) : ft_strdup(buffptr);
	free(buffptr);
	return (ptr);
}
