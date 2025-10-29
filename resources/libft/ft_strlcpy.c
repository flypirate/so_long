/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:29:55 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 18:07:44 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//c added to get len of src 

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = ft_strlen(src);
	if (!dst)
		return (c);
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}
/*
int	main(void)
{
	unsigned long i = 0;
	char buf[60] = "       ";
	char s[50] = "lorem ipsum dolor sit amet";
	
	ft_strlcpy(buf, s, sizeof(buf));
	while (i < sizeof(buf))
	{
		write(1, &buf[i], 1);
		i++;
	}
	return (0);
}
*/
