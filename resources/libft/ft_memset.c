/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:33:01 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/21 21:27:05 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    int i = 0;
    char buffer[12] = "Hello World";
    
    ft_memset(buffer, 'c', 5);
    while (buffer[i] != '\0')
    {
        write(1, &buffer[i], 1);
        i++;
    }
    return (0);
}
*/
