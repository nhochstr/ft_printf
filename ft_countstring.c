/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:10:05 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:38:00 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_countstring(char const *s, char *str)
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
