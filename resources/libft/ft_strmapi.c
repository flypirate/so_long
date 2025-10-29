/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:46:06 by albertogm         #+#    #+#             */
/*   Updated: 2025/04/22 21:39:50 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;
	int				size;

	if (!s)
		return (NULL);
	size = strlen(s);
	new_string = malloc(size + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[size] = '\0';
	return (new_string);
}
/*
static char f(unsigned int position, char c)
{
	char new_char;

	if (c >= 'a' && c <= 'z' && position % 2 == 1)
	{
		new_char = (c - 32);
		return (new_char);
	}
	else
	{
		return (c);
	}
}

int main(void)
{
	char *string = "hola bebés";
	int i = 0;
	char *result = ft_strmapi(string, f);

	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return (0);
}
	*/
