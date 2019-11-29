/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repspczeroxup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:30:12 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:30:44 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
