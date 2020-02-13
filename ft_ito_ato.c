/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ito_ato.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:49:20 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:44:48 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int				ft_atoi(const char *str)
{
	int					k;
	unsigned long long	n;

	k = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		k = -k;
	if (*str == '+' || *str == '-')
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	if (n > 9223372036854775807 && k < 0)
		return (0);
	if (n > 9223372036854775807 && k > 0)
		return (-1);
	return (n * k);
}

char			*ft_itoa_long(long n)
{
	char	*str;
	long	nb;
	long	i;

	nb = n;
	i = ft_countnbr(nb);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}

unsigned int	ft_itou(int i)
{
	unsigned int	u;

	if (i < 0)
		u = 2147483647 + 2147483649 + i;
	else
		u = i;
	return (u);
}

char			*ft_itox(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexa(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}

char			*ft_itoxupper(long nbr)
{
	char	*buffptr;

	buffptr = ft_calloc(2, sizeof(char *));
	buffptr = ft_converthexaupper(nbr, buffptr, 0);
	buffptr = ft_revtab(buffptr);
	return (buffptr);
}
