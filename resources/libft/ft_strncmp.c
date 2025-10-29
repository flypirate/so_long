/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:58:08 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/23 22:29:35 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (string1[i] && string2[i] && (i < n))
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
		else
			i++;
	}
	if ((string1[i] != '\0' || string2[i] != '\0') && (i < n))
		return (string1[i] - string2[i]);
	return (0);
}
/*
int main(void)
{
    const char *s1 = "Holb";
    const char *s2 = "Hola";
    int bytes = 20;
    char result = ft_strncmp(s1, s2, bytes) + '0';
    
    write(1, (&result), 1);
    return (0);
}
*/
