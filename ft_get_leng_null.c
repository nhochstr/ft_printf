/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leng_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:09:26 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:44:07 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_getleng(int leng)
{
	static int i = 0;

	if (leng > 0)
		i = leng;
	return (i);
}

int	ft_getnbr0(int i)
{
	static int	nbr = 0;
	int			mem;

	if (i > 0)
		nbr = nbr + 1;
	mem = nbr;
	if (i < 0)
		nbr = 0;
	return (mem);
}
