/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:53:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/06 12:54:00 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(char *hexa, int count, unsigned long num)
{
	if (num != 0)
	{
		count = ft_hexa(hexa, count, num / 16);
		count += ft_print_char(hexa[num % 16]);
	}
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	num;
	char			*hexa;
	int				check;

	count = 0;
	num = (unsigned long)ptr;
	hexa = "0123456789abcdef";
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	check = 0;
	if (num == 0)
	{
		check = write(1, "0", 1);
		if (check == -1)
			return (-1);
		return (3);
	}
	count = ft_hexa(hexa, count, num) + 2;
	return (count);
}
