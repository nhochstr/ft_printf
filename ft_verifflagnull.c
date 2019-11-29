/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifflagnull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:24:35 by nhochstr          #+#    #+#             */
/*   Updated: 2019/11/29 23:46:46 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_verifflagnull(t_spec spec)
{
	if (spec.flags != '0')
		return (1);
	if (spec.type == 'c' || spec.type == 'p' || spec.type == 's')
		return (0);
	return (1);
}
