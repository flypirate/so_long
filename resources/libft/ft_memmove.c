/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:17:34 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/26 16:46:47 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	if (destination == source || len == 0)
		return (dst);
	if (destination > source)
	{
		while (len-- > 0)
		{
			destination[len] = source[len];
		}
	}
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
    char destination[12] = "Hello World";
    char source[17] = "Goodbye Universe";
    int i = 0;
    
    ft_memmove(destination, source, 12);
    while (i < 16)
    {
        write(1, &destination[i], 1);
        i++;
    }    
    return (0);
}
*/
