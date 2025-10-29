/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:48:26 by albertogm         #+#    #+#             */
/*   Updated: 2025/04/24 21:24:02 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	min_case(int fd)
{
	write(fd, "-2147483648", 11);
}

static void	single_digit_case(int n, int fd)
{
	char	towrite;

	towrite = n + '0';
	write(fd, &towrite, 1);
}

static void	write_num(int n, int fd)
{
	char	towrite;

	ft_putnbr_fd(n / 10, fd);
	towrite = (n % 10) + '0';
	write(fd, &towrite, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		min_case(fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n >= 1 && n < 10)
	{
		single_digit_case(n, fd);
		return ;
	}
	write_num(n, fd);
	return ;
}
/*
int main(void)
{
	int number = -689;
	
	ft_putnbr_fd(number, 1);
	return (0);
}
*/
