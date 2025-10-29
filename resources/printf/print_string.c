/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:52:22 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/12 19:13:43 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *string_value)
{
	int	i;

	i = 0;
	if (!string_value)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string_value[i])
	{
		write (1, &string_value[i], 1);
		i++;
	}
	return (i);
}
