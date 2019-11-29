/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:24:01 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:45:15 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_itox(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexa(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}
