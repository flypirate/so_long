/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:49:48 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 19:40:50 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long		i;
	unsigned char		character;
	unsigned char		*pointer;

	character = (unsigned char)c;
	pointer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pointer[i] == character)
		{
			return ((void *)&pointer[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char *string = "Hola ayuda por dios";
    char c = 'p';
    int bytes = 19;
    char *result = ft_memchr(string, c, bytes);
    int i = 0;
    
    while (i <= 8)
    {
        write(1, &result[i], 1);
        i++;
    }
    return (0);
}*/
