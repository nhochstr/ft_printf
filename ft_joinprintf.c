/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:18:50 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/08 18:22:37 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
//
#include <stdio.h>
size_t	ft_strlenprintf(const char *s)
{
	size_t	i;
	int		j;
	int		nbrnull;

	nbrnull = ft_getnbr0(0);
	i = 0;
	j = 0;
	while (j < nbrnull && nbrnull != 0)
	{
		if (s[i] == '\0')
			j++;
		i++;
	}
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlennull(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	while (s[i] != '\0')
		i++;
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
	while (j < ft_getnbr0(0) && ft_getnbr0(0) != 0)
	{
		if (s1[i] == '\0')
			j++;
		ptr[i] = s1[i];
		i++;
	}
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
	while (j < ft_getnbr0(0) && ft_getnbr0(0) != 0)
	{
		if (s1[i] == '\0')
			j++;
		ptr[i] = s1[i];
		i++;
	}
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = s2[j];
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

char	*ft_dupnull(const char *s)
{
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(ptr = malloc(ft_strlennull(s) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = s[i];
	i++;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_joinprintf_to(char const *s1, char const *s2, char c)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	leng = ft_strlenprintf((char*)s1) + ft_strlento((char*)s2, c);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (j < ft_getnbr0(0) && ft_getnbr0(0) != 0)
	{
		if (s1[i] == '\0')
			j++;
		ptr[i] = s1[i];
		i++;
	}
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
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
