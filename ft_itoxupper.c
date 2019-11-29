/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:25:24 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:45:27 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_itoxupper(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexaupper(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}
