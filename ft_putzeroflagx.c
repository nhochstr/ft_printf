/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeroflagx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:27:50 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:28:29 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_putzeroflagx(char *buff, int neg)
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
