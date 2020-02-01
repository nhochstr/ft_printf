/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:18:30 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/01 10:59:12 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_strjoin_to(char const *s1, char const *s2, char c)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	leng = ft_strlen((char*)s1) + ft_strlento((char*)s2, c);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != c && s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	if (s1)
		free((char *)s1);
	return (ptr);
}
