/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:33 by albertogm         #+#    #+#             */
/*   Updated: 2025/04/24 19:17:50 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	temp;
	int	i;

	temp = n;
	i = 0;
	if (n < 0)
		temp = n * -1;
	while (temp > 0)
	{
		i++;
		temp = temp / 10;
	}
	return (i);
}

static char	*create_number(int n, char *number, int len, long temp)
{
	temp = n;
	if (n < 0)
	{
		number[0] = '-';
		temp = -temp;
	}
	while (temp > 0)
	{
		number[len - 1] = ((temp % 10) + '0');
		temp = temp / 10;
		len--;
	}
	return (number);
}

static char	*min_case(void)
{
	char	*number;

	number = malloc(12 * sizeof(char));
	if (!number)
		return (NULL);
	ft_strlcpy(number, "-2147483648", 12);
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	temp;
	int		len;

	temp = n;
	if (n == 0)
	{
		number = malloc(2);
		if (!number)
			return (NULL);
		number[0] = '0';
		number[1] = '\0';
		return (number);
	}
	if (n == -2147483648)
		return (min_case());
	len = intlen(n);
	if (n < 0)
		len++;
	number = malloc(len + 1);
	if (!number)
		return (NULL);
	number[len] = '\0';
	return (create_number(n, number, len, temp));
}
/*
int main(void)
{
	int number =   -5432;
	char *result = ft_itoa(number);
	int i = 0;

	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return (0);
}
*/
