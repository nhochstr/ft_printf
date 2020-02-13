/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:22:33 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:17:25 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_converthexa(long nbr, char *buffptr, int i)
{
	if (nbr >= 16)
		buffptr = ft_converthexa(nbr / 16, buffptr, i + 1);
	nbr = nbr % 16 + 48;
	if (nbr > 57)
		nbr += 39;
	buffptr[i] = nbr;
	return (buffptr);
}

char	*ft_converthexaupper(long nbr, char *buffptr, int i)
{
	if (nbr >= 16)
		buffptr = ft_converthexaupper(nbr / 16, buffptr, i + 1);
	nbr = nbr % 16 + 48;
	if (nbr > 57)
		nbr += 7;
	buffptr[i] = nbr;
	return (buffptr);
}
