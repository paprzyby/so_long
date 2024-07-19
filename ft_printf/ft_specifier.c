/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:07:01 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/06 12:56:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list arg_lst, const char *str)
{
	if (*str == 'c')
		return (ft_print_char(va_arg(arg_lst, int)));
	else if (*str == 's')
		return (ft_print_str(va_arg(arg_lst, char *)));
	else if (*str == 'p')
		return (ft_print_ptr(va_arg(arg_lst, void *)));
	else if (*str == 'd')
		return (ft_print_num(va_arg(arg_lst, int)));
	else if (*str == 'i')
		return (ft_print_num(va_arg(arg_lst, int)));
	else if (*str == 'u')
		return (ft_print_unsigned(va_arg(arg_lst, unsigned int)));
	else if (*str == 'x')
		return (ft_print_hexa((unsigned int)va_arg(arg_lst, int), 1));
	else if (*str == 'X')
		return (ft_print_hexa((unsigned int)va_arg(arg_lst, int), 2));
	else if (*str == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}

//the va_arg macro retrieves the next argument