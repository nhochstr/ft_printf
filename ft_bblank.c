/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bblank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:25:41 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:26:06 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bblank(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = ' ';
}