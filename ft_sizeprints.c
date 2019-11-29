/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeprints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:27:58 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 21:28:15 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	ft_sizeprints(t_spec spec, char *copy)
{
	int	size;
	int				leng;

	leng = ft_strlen(copy);
	size = leng;
	if (spec.precision >= 0 && leng > spec.precision)
		size = spec.precision;
	if (spec.width > size)
		size = spec.width;
	return (size);
}