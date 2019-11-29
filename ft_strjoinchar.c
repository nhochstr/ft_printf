/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:16:52 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:42:54 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_strjoinchar(char const *s1, char const s2)
{
	char	*ptr;
	int		i;
	int		leng;

	leng = ft_strlen((char*)s1) + 1;
	i = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;

	ptr[i++] = s2;
	ptr[i] = '\0';
	return (ptr);
}
