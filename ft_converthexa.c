/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:22:33 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:37:44 by nhochstr         ###   ########.fr       */
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
