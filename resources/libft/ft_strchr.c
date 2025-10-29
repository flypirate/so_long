/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:58:03 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 23:23:23 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	locate;

	i = 0;
	locate = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == locate)
			return ((char *)&s[i]);
		i++;
	}
	if (locate == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
    int i = 0;
    const char *string = "Hola mundo";
    char locate = 'l';

    char *result = ft_strchr(string, locate);
    while (result[i] != '\0')
    {
        write(1, &result[i], 1);
        i++;
    }
    return (0);
}
*/
