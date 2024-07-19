/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:54:12 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/06 12:07:05 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(unsigned long num, char *base)
{
	int	count;
	int	check;

	count = 0;
	if (num >= 16)
	{
		count += ft_base(num / 16, base);
		count += ft_base(num % 16, base);
	}
	else
	{
		check = ft_print_char(base[num]);
		if (check == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_print_hexa(unsigned long num, int base)
{
	int	count;

	if (base == 1)
		count = ft_base(num, "0123456789abcdef");
	else
		count = ft_base(num, "0123456789ABCDEF");
	return (count);
}
