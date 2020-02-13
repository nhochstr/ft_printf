/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:25:24 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/12 16:42:59 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoxupper(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexaupper(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}
