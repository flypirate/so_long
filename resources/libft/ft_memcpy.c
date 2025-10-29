/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:33:22 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/21 21:27:43 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*p;
	const unsigned char	*source;

	i = 0;
	p = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		p[i] = source[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    int i = 0;
    char destination[28] = "a";
    char source[27] = "b";

    ft_memcpy(destination, source, 27);
    while (i < 27)
    {
        write(1, &destination[i], 1);
        i++;
    }
    return (0);
}
*/
