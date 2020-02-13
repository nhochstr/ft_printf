/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:49:20 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/13 11:17:00 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = 0;
}

void	ft_bblank(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = ' ';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_malloc_space(size_t count, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(count * size + 1)))
		return (NULL);
	ft_bblank(ptr, count * size);
	ptr[count] = 0;
	return (ptr);
}
