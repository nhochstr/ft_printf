/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtabpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:49:16 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:17:07 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_revtabpointer(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
	buffptr = ft_strjoins1(buffptr, "x0");
	leng = ft_strlen(buffptr) - 1;
	while (i <= leng)
	{
		c = buffptr[i];
		buffptr[i] = buffptr[leng];
		buffptr[leng] = c;
		i++;
		leng--;
	}
	return (buffptr);
}
