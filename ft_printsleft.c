/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:47:31 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 10:14:17 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printsleft(t_spec spec, char *copy, char *buff, unsigned int size)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (spec.width == 0)
		spec.width = size;
	if (spec.precision < 0)
		spec.precision = size;
	if (spec.flags == '-')
	{
		while (buff[i[1]] != 0 && i[0]++ < spec.precision && copy[i[2]] != '\0')
			buff[i[1]++] = copy[i[2]++];
	}
	else
	{
		i[1] = ft_strlen(buff) - 1;
		i[2] = ft_strlen(copy) - 1;
		if (i[2] >= spec.precision)
			i[2] = spec.precision - 1;
		while (i[1] >= 0 && i[2] >= 0)
			buff[i[1]--] = copy[i[2]--];
	}
	return (buff);
}
