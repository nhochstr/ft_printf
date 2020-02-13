/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:23:31 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:16:43 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_revtab(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
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
