/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:14:35 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:31:27 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_strdupchar(char s)
{
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) + 1)))
		return (NULL);
	ptr[0] = s;
	ptr[1] = '\0';
	return (ptr);
}
