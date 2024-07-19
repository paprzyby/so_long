/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:55:29 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/06 12:56:06 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_lst;
	int		count;
	int		check;

	va_start(arg_lst, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check = ft_specifier(arg_lst, str);
			str++;
		}
		else
		{
			check = write(1, str, 1);
			str++;
		}
		if (check == -1)
			return (-1);
		count = count + check;
	}
	va_end(arg_lst);
	return (count);
}
