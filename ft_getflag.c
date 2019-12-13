/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:20:30 by nhochstr          #+#    #+#             */
/*   Updated: 2019/12/13 14:40:50 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_getflag(const char *format, int leng)
{
	char c;

	c = 0;
	while (format[leng] == '-' || format[leng] == '0')
	{
		if (format[leng] == '-')
			return (format[leng]);
		if (format[leng] == '0')
			c = '0';
		leng++;
	}
	return (c);
}
