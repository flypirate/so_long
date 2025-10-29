/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:32:05 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/14 13:10:04 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	selector(char const *argument, int i, va_list ap)
{
	if (argument[i] == 'i' || argument[i] == 'd')
		return (print_int(va_arg(ap, int)));
	if (argument[i] == 's')
		return (print_string(va_arg(ap, char *)));
	if (argument[i] == 'p')
		return (print_pointer(va_arg(ap, void *)));
	if (argument[i] == 'u')
		return (print_unsigned(va_arg(ap, unsigned int)));
	if (argument[i] == 'x' || argument[i] == 'X')
		return (print_hex(va_arg(ap, unsigned int), argument[i]));
	if (argument[i] == 'c')
		return (print_char(va_arg(ap, int)));
	if (argument[i] == '%')
		return (print_percent('%'));
	return (0);
}

int	ft_printf(char const *argument, ...)
{
	int		i;
	int		f;
	va_list	ap;

	va_start(ap, argument);
	i = 0;
	f = 0;
	while (argument[i])
	{
		if (argument[i] == '%')
		{
			i++;
			f = f + selector(argument, i, ap);
			i++;
		}
		else
		{
			f += print_char(argument[i]);
			i++;
		}
	}
	va_end(ap);
	return (f);
}
