/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:47:31 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:47:49 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_printsleft(t_spec spec, char *copy, char *buff, unsigned int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (spec.width == 0)
		spec.width = size;
	if (spec.precision < 0)
		spec.precision = size;
	if (spec.flags == '-')
	{
		while (buff[j] != 0 && i++ < spec.precision && copy[k] != '\0')
			buff[j++] = copy[k++];
	}
	else
	{
		j = ft_strlen(buff) - 1;
		k = ft_strlen(copy) - 1;
		if (k >= spec.precision)
			k = spec.precision - 1;
		while (j >= 0 && k >= 0)
			buff[j--] = copy[k--];
	}
	return (buff);
}