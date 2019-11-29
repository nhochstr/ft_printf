/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:49:56 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:50:13 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ptr_addr(long addr, char *buffptr, int i)
{
	if (addr >= 16)
		buffptr = ptr_addr(addr / 16, buffptr, i + 1);
	addr = addr % 16 + 48;
	if (addr > 57)
		addr += 39;
	buffptr[i] = addr;
	return (buffptr);
}