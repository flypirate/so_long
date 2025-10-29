/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:33:43 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/21 20:51:46 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
	{
		return (0);
	}
}
/*
int main(void)
{
    char test;
    char result;

    test = '6';
    result = ft_isdigit(test) + '0';
    write(1, &result, 1);
    return (0);
}
*/
