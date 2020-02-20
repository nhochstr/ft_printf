/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_space_zero.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:53:27 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/20 22:33:56 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_replacespacezero(char *buff, t_spec spec)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (buff[i] == ' ')
		i++;
	if (buff[i] == '-')
		neg = 1;
	if (spec.flags == '0')
		buff = ft_putzeroflag(buff, neg);
	else
		buff = ft_putzeroprec(buff, neg, spec);
	return (buff);
}

char	*ft_repspczerox(char *buff, t_spec spec)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (buff[i] == ' ')
		i++;
	if (buff[i] == '-')
		neg = 1;
	if (spec.flags == '0')
		buff = ft_putzeroflagx(buff, neg);
	else
		buff = ft_putzeroprecx(buff, neg, spec);
	return (buff);
}

char	*ft_repspczeroxup(char *buff, t_spec spec)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (buff[i] == ' ')
		i++;
	if (buff[i] == '-')
		neg = 1;
	if (spec.flags == '0')
		buff = ft_putzeroflagx(buff, neg);
	else
		buff = ft_putzeroprecxup(buff, neg, spec);
	return (buff);
}

char	*ft_repspczerop(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == ' ')
			buff[i] = '0';
		i++;
	}
	return (buff);
}

char	*ft_repspczeros(char *buff, int size)
{
	int	i;

	i = 0;
	while (buff[i] != '\0' && i < size)
	{
		if (buff[i] == ' ')
			buff[i] = '0';
		i++;
	}
	return (buff);
}
