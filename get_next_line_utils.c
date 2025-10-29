/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:36:32 by albegar2          #+#    #+#             */
/*   Updated: 2025/06/17 16:45:15 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//custom because I use char instead of const char
size_t	custom_strlen(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

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

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
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

//custom because I use char instead of const char
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= custom_strlen(s))
	{
		substring = malloc(1);
		if (!substring)
			return (NULL);
		return (substring[0] = '\0', substring);
	}
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		f;
	size_t		s1len;
	size_t		s2len;

	i = 0;
	f = 0;
	s1len = custom_strlen(s1);
	s2len = custom_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	result = malloc(s1len + s2len + 1);
	if (!result)
		return (NULL);
	while (i < (s1len))
	{
		result[i] = s1[i];
		i++;
	}
	while (i < (s1len + s2len))
		result[i++] = s2[f++];
	result[i] = '\0';
	return (result);
}
