/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:29:11 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/21 21:26:48 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		result = result + 1;
		i++;
	}
	return (result);
}
/*
int main(void)
{
	char *str = "here";
	size_t result;
 
	result = ft_strlen(str) + '0';
	write(1, &result, 1);
	return (0);
}
*/
