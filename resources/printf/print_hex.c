/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:09:20 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/14 13:09:23 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(char *hexadecimal, unsigned int hex_value, char mayus)
{
	int	i;
	int	digit;

	i = 0;
	while (hex_value)
	{
		digit = hex_value % 16;
		if (digit >= 10)
		{
			if (mayus == 'X')
				hexadecimal[i] = digit - 10 + 'A';
			if (mayus == 'x')
				hexadecimal[i] = digit - 10 + 'a';
		}
		else
			hexadecimal[i] = digit + '0';
		hex_value = hex_value / 16;
		i++;
	}
	hexadecimal[i] = '\0';
	return (i);
}

int	print_hex(unsigned int hex_value, char mayus)
{
	char	*hexadecimal;
	int		i;
	int		save;

	hexadecimal = malloc(sizeof(unsigned int) * 2 + 1);
	if (!hexadecimal)
		return (0);
	if (hex_value == 0)
	{
		i = 0;
		write(1, "0", 1);
		free(hexadecimal);
		return (1);
	}
	i = conversion(hexadecimal, hex_value, mayus);
	save = i;
	while (i > 0)
	{
		write(1, &hexadecimal[i - 1], 1);
		i--;
	}
	free(hexadecimal);
	return (save);
}
