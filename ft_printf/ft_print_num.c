/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:46:46 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/05 13:05:09 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numbers(int num)
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

static int	minus(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)s1;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int num)
{
	size_t	size;
	char	*str;
	int		negative;

	size = numbers(num);
	negative = 0;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num < 0)
		negative++;
	num = minus(num);
	if (negative)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = num % 10 + '0';
		num = num / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

int	ft_print_num(int num)
{
	char	*str;
	int		count;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	count = ft_print_str(str);
	free(str);
	return (count);
}
