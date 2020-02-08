/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:22:54 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 12:47:44 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"

long	ft_getprecision(const char *format, int leng, va_list args)
{
	if (format[leng] == '.')
		leng++;
	else
		return (-1);
	if (format[leng] == '*')
		return (va_arg(args, int));
	else if (ft_isdigit(format[leng]) == 1)
		return (ft_atoi(&format[leng]));
	return (0);
}
