/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:49:20 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:45:31 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s = s + 1;
	}
	return (i);
}

size_t			ft_strlenprintf(const char *s)
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

size_t			ft_strlennull(const char *s)
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

unsigned long	ft_strlento(char *str, char c)
{
	unsigned long	i;

	i = 0;
	while (*str != '\0' && *str != c)
	{
		i++;
		str = str + 1;
	}
	return (i);
}

int				ft_printflen(char *ptr, const char *format)
{
	int	i;

	i = 1;
	if (ptr[0] == '\0' && format[0] == '%')
	{
		while (format[i] == '0' || format[i] == '-' || format[i] == '.' ||
			ft_isdigit(format[i]) == 1 || format[i] == 'c' || format[i] == '*')
		{
			if (format[i] == 'c')
				return (1);
			i++;
		}
	}
	return (ft_strlen(ptr));
}
