/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:05:28 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 22:48:11 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static int	spaces(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] != '\0')
	{
		if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		else
			break ;
	}
	return (i);
}

static int	conversion(const char *nptr)
{
	int	i;
	int	number;
	int	sign;

	i = spaces(nptr);
	number = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}

int	ft_atoi(const char *nptr)
{
	int	number;

	number = conversion(nptr);
	return (number);
}
/*
int main(void)
{
    char *string = "R 83";
    int result = ft_atoi(string);
    
    printf("%d\n", result);
    return (0);
}
*/
