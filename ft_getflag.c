/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:20:30 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:20:45 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_getflag(const char *format, int leng)
{
	if (format[leng] == '-' || format[leng] == '0')
		return (format[leng]);
	return (0);
}