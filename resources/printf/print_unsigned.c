/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:01:37 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/14 13:09:11 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int		i;
	char	towrite;

	i = 0;
	if (n <= 9)
	{
		towrite = n + '0';
		write(1, &towrite, 1);
		i++;
	}
	else
	{
		i += print_unsigned(n / 10);
		towrite = (n % 10) + '0';
		write(1, &towrite, 1);
		i++;
	}
	return (i);
}
