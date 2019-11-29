/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:23:57 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:24:10 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char ft_gettype(const char *format, int leng)
{
	if (format[leng] == 'c')
		return ('c');
	if (format[leng] == 's')
		return ('s');
	if (format[leng] == 'p')
		return ('p');
	if (format[leng] == 'd')
		return ('d');
	if (format[leng] == 'i')
		return ('i');
	if (format[leng] == 'u')
		return ('u');
	if (format[leng] == 'x')
		return ('x');
	if (format[leng] == 'X')
		return ('X');
	return (0);
}