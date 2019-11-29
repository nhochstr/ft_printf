/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeroflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:52:00 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:28:22 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_putzeroflag(char *buff, int neg)
{
	long i;

	i = 0;
	if (neg == 1)
	{
		i = 1;
		buff[0] = '-';
	}
	while (buff[i] == ' ' || buff[i] == '-')
		buff[i++] = '0';
	return (buff);
}
