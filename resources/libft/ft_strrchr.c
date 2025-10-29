/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:57:41 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/25 22:24:37 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				f;
	unsigned char	locate;
	char			*position;

	i = ft_strlen(s);
	f = 0;
	locate = (unsigned char)c;
	position = NULL;
	while (f <= i)
	{
		if (s[f] == locate)
			position = (char *)s + f;
		f++;
	}
	return (position);
}
/*
int main(void)
{
    int i = 0;
    const char *string = "";
    char locate = '\0';

    char *result = ft_strrchr(string, locate);
    while (result[i] != '\0')
    {
        write(1, &result[i], 1);
        i++;
    }
    return (0);
}
*/
