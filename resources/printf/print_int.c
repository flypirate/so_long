/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:51:44 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/12 16:58:41 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursion(int n, int i)
{
	char	towrite;

	i += print_int(n / 10);
	towrite = (n % 10) + '0';
	i++;
	write(1, &towrite, 1);
	return (i);
}

int	print_int(int int_value)
{
	int		i;
	char	towrite;

	i = 0;
	if (int_value == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (int_value < 0)
	{
		write(1, "-", 1);
		int_value = int_value * -1;
		i++;
	}
	if (int_value >= 0 && int_value <= 9)
	{
		towrite = int_value + '0';
		i++;
		write(1, &towrite, 1);
	}
	else
		i = recursion(int_value, i);
	return (i);
}
