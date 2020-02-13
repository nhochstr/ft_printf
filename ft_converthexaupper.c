/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexaupper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:23:02 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:10:49 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
