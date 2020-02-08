/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:48:11 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 12:01:59 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int		ft_getnbr0(int i)
{
	static int	nbr = 0;
	int			mem;

	mem = nbr;
	if (i > 0)
		nbr = nbr + i;
	if (i < 0)
		nbr = 0;
	return (mem);
}
