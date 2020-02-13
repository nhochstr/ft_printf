/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:23:31 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:35:12 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_revtab(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
	leng = ft_strlen(buffptr) - 1;
	while (i <= leng)
	{
		c = buffptr[i];
		buffptr[i] = buffptr[leng];
		buffptr[leng] = c;
		i++;
		leng--;
	}
	return (buffptr);
}

char	*ft_revtabpointer(char *buffptr)
{
	int		leng;
	int		i;
	char	c;

	i = 0;
	buffptr = ft_strjoins1(buffptr, "x0");
	leng = ft_strlen(buffptr) - 1;
	while (i <= leng)
	{
		c = buffptr[i];
		buffptr[i] = buffptr[leng];
		buffptr[leng] = c;
		i++;
		leng--;
	}
	return (buffptr);
}

char	*ft_switchspace(char *buff)
{
	char			*ptr;
	unsigned long	i;
	unsigned long	j;

	ptr = ft_strdup(buff);
	i = 0;
	j = 0;
	while (buff[i] == ' ')
		i++;
	while (buff[i] != '\0')
		ptr[j++] = buff[i++];
	while (ptr[j] != '\0')
		ptr[j++] = ' ';
	free(buff);
	return (ptr);
}
