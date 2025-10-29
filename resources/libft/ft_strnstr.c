/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:20:31 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 19:06:12 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while ((big[i] != '\0') && i < len)
	{
		if (big[i] == little[0])
		{
			f = 0;
			while (((i + f) < len) && (big[i + f] == little[f]) && (little[f]))
			{
				f++;
			}
			if (little[f] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char *larga = "Hola hola hola";
    char *corta = "hola";
    int bytes = 50;
    int i = 0;
    
    char *result = ft_strnstr(larga, corta, bytes);
    while (result[i] != '\0')
    {
        write(1, &result[i], 1);
        i++;
    }
    return (0);
}
*/
