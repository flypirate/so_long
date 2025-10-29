/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:39:12 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/21 21:21:40 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// n == 0 is there in case both strings are empty

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long		i;
	unsigned char		*string1;
	unsigned char		*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (string1[i] == string2[i])
		{
			i++;
		}
		else
		{
			return ((int)string1[i] - string2[i]);
		}
	}
	return (0);
}
/*
int main(void)
{
    const char *s1 = "";
    const char *s2 = "";
    int bytes = 20;
    char result = ft_memcmp(s1, s2, bytes) + '0';
    
    write(1, (&result), 1);
    return (0);
}
*/
