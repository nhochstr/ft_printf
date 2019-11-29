/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:16:03 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:31:21 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_strdup_to(char *s, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc(ft_strlento((char*)s, '%') * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
