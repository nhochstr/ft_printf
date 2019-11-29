/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacespacezero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:53:27 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:30:08 by nhochstr         ###   ########.fr       */
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
