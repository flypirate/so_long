/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:51:21 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/22 21:37:43 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief duplicate string with malloc
/// @param s string
/// @return pointer to new string
char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	i = i + 1;
	new_string = malloc(i * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
int main(void)
{
    char *original_string = "Hola bebes";
    char *pointer = ft_strdup(original_string);
    int i = 0;
    
    while (pointer[i] != '\0')
    {
        write(1, &pointer[i], 1);
        i++;
	}
	free(pointer);
    return (0);
}
*/
