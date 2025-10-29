/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:51:05 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 19:42:59 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;
	size_t	total_bytes;

	i = 0;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	if (nmemb * size > __INT_MAX__)
	{
		return (NULL);
	}
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	total_bytes = nmemb * size;
	while (i < total_bytes)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}
/*
int main(void)
{
    int i = 0;
    char *result = ft_calloc(5, 1);

    printf("%p\n", result);
    while (result[i] != '\0')
    {
        write(1, &result[i], 1);
        i++;
    }    
    free(result);
    return (0);
}
*/
