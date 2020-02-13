/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:52:00 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:33:19 by nhochstr         ###   ########.fr       */
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

char	*ft_putzeroprecxup(char *buff, int neg, t_spec spec)
{
	long	i;
	long	size;

	size = ft_strlen(buff) - 1;
	i = size - spec.precision;
	while (ft_ishexaupper(buff[size]) == 1)
		size--;
	while (size > i && size >= 0)
		buff[size--] = '0';
	if (size < 0 && neg == 1)
		buff = ft_strjoins2("-", buff);
	if (size >= 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}
