/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:54:11 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/01 11:47:56 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

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
