/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeroprecx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:28:23 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 14:52:55 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_putzeroprecx(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_ishexa(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoins2("-", buff);
	if (size >= 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}
