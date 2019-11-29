/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:27:09 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 22:45:43 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_malloc_space(size_t count, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(count * size + 1)))
		return (NULL);
	ft_bblank(ptr, count * size);
	ptr[count] = 0;
	return (ptr);
}
