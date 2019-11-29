/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:18:30 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:32:10 by nhochstr         ###   ########.fr       */
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

	leng = ft_strlen((char*)s1) + ft_strlento((char*)s2, c);
	i = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2 != c && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
