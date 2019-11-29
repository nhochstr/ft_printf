/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtabpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:49:16 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:31:04 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_revtabpointer(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
	buffptr = ft_strjoin(buffptr, "x0");
	leng = ft_strlen(buffptr) - 1;

	while(i <= leng)
	{
		c = buffptr[i];
		buffptr[i] = buffptr[leng];
		buffptr[leng] = c;
		i++;
		leng--;
	}
	return (buffptr);
}
