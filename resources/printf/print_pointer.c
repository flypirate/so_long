/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:51:46 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/14 13:09:47 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*conv_hex(uintptr_t int_pointer)
{
	char	*hexadecimal;
	int		i;
	int		digit;

	i = 0;
	hexadecimal = malloc(17 * sizeof(char));
	if (!hexadecimal)
		return (0);
	while (int_pointer)
	{
		digit = int_pointer % 16;
		if (digit >= 10)
			hexadecimal[i] = digit - 10 + 'a';
		else
			hexadecimal[i] = digit + '0';
		int_pointer = int_pointer / 16;
		i++;
	}
	hexadecimal[i] = '\0';
	return (hexadecimal);
}

int	print_pointer(void *pointer_value)
{
	int			i;
	uintptr_t	int_pointer;
	char		*hexadecimal;
	int			size;

	if (!pointer_value || pointer_value < 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 2;
	int_pointer = (uintptr_t)pointer_value;
	hexadecimal = conv_hex(int_pointer);
	size = ft_strlen(hexadecimal) - 1;
	write(1, "0x", 2);
	while (size > -1)
	{
		write(1, &hexadecimal[size--], 1);
		i++;
	}
	free(hexadecimal);
	return (i);
}
