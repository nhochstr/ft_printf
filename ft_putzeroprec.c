/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeroprec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:52:43 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 14:52:50 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
//
#include <stdio.h>

char	*ft_putzeroprec(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_isdigit(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoins2("-", buff);
	if (size >= 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}
