/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:34:44 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/02 11:32:12 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numbers(unsigned int num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_unsigned(unsigned int num)
{
	size_t	size;
	char	*str;

	size = numbers(num);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		count;

	str = ft_itoa_unsigned(num);
	if (!str)
		return (-1);
	count = ft_print_str(str);
	free(str);
	return (count);
}
