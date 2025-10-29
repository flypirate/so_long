/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:52:57 by albertogm         #+#    #+#             */
/*   Updated: 2025/04/29 18:06:12 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	create_string(char *new, char const *s1, int start, int last)
{
	int	c;

	c = 0;
	while (start <= last)
	{
		new[c] = s1[start];
		start++;
		c++;
	}
	new[c] = '\0';
}

static char	*empty_case(void)
{
	char	*empty_string;

	empty_string = malloc(sizeof(char));
	if (!empty_string)
		return (NULL);
	empty_string[0] = '\0';
	return (empty_string);
}

static char	*malloc_string(char const *s1, int start, int last)
{
	char	*new_string;

	new_string = malloc((last - start + 2) * sizeof(char));
	if (!new_string)
		return (NULL);
	create_string(new_string, s1, start, last);
	return (new_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	if (*s1 == '\0')
		return (empty_case());
	last = ft_strlen(s1) - 1;
	while (s1[start] && check_set(s1[start], set))
	{
		start++;
	}
	while (last >= 0 && s1[last] && check_set(s1[last], set))
	{
		last--;
	}
	if (start > last)
		return (empty_case());
	return (malloc_string(s1, start, last));
}
/*
int	main(void)
{
	char *original = "";
	char *set = "";
	int i = 0;
	char *result = ft_strtrim(original, set);
	
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}	
	free(result);
	return (0);
}
*/
