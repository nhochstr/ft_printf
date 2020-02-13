/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnomalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:18:50 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 08:30:47 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_joinwithoutmalloci(char *s1, const char *s2, int i)
{
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	return (i);
}

int		ft_joinwithoutmallocij(char *s1, const char *s2, int i, int j)
{
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	return (j);
}

int		ft_joinwithoutmalloczero(char *s1, const char *s2)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < ft_getnbr0(0) && ft_getnbr0(0) != 0)
	{
		if (s2[i] == '\0')
			j++;
		s1[i] = s2[i];
		i++;
	}
	return (i);
}
