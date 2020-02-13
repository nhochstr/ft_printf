/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nbr_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:40:30 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:44:23 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_countnbr(long nbr)
{
	long i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i = 1;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		ft_countstring(char const *s, char *str)
{
	int	i;
	int	j;
	int nbr;

	i = 0;
	nbr = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == str[j])
		{
			j++;
			if (str[j] == 0)
			{
				nbr++;
				j = 0;
			}
		}
		else
			j = 0;
		i++;
	}
	return (nbr);
}
