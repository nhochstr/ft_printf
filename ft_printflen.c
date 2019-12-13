/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:37:45 by nhochstr          #+#    #+#             */
/*   Updated: 2019/12/12 15:46:30 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_printflen(char *ptr, const char *format)
{
	int	i;

	i = 1;
	if (ptr[0] == '\0' && format[0]== '%')
	{
		while (format[i] == '0' || format[i] == '-' || format[i] == '.' || 
			ft_isdigit(format[i]) == 1 || format[i] == 'c' || format[i] == '*')
		{
			if (format[i] == 'c')
				return (1);
			i++;
		}
	}
	return(ft_strlen(ptr));
}
