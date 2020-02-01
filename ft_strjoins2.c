/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:20:34 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/01 11:20:48 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_strjoins2(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free((char *)s2);
	return (ptr);
}