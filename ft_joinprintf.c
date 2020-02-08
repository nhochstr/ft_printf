/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:18:50 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 17:03:44 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

size_t	ft_strlenprintf(const char *s)
{
	size_t	i;
	int		nbrnull;

	nbrnull = ft_getnbr0(0);
	i = 0;
	while (*s != '\0' && i <= nbrnull)
	{
		i++;
		s = s + 1;
	}
	return (i);
}

size_t	ft_strlenprintf(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s = s + 1;
	}
	i++;
	while (*s != '\0')
	{
		i++;
		s = s + 1;
	}
	return (i);
}

char	*ft_joinprintf(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlenprintf(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0' && i <= ft_getnbr0(0))
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
	free((char *)s1);
	return (ptr);
}

char	*ft_joinprintfnull(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlenprintf(s1) + ft_strlennull(s2);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0' && i <= ft_getnbr0(0))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	j++;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free((char *)s1);
	return (ptr);
}

