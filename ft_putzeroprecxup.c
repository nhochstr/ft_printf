/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeroprecxup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:29:07 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:29:55 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

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
		buff = ft_strjoin("-", buff);
	if (size > 0 && neg == 1)
		buff[size] = '-';
	return (buff);
}
