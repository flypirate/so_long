/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:46:30 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/29 18:06:47 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy(char *dst, const char *src, size_t i_dest, size_t size)
{
	int	i;

	i = 0;
	while ((src[i] != '\0') && (i_dest < size - 1))
	{
		dst[i_dest] = src[i];
		i_dest++;
		i++;
	}
	if (i_dest < size)
	{
		dst[i_dest] = '\0';
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_total;
	size_t	src_total;

	dest_total = 0;
	src_total = 0;
	while (dst[dest_total] != '\0')
	{
		dest_total++;
	}
	while (src[src_total] != '\0')
	{
		src_total++;
	}
	if (dest_total >= size)
	{
		return (size + src_total);
	}
	copy(dst, src, dest_total, size);
	return (dest_total + src_total);
}
/*
int main(void)
{
    int i = 0;
    int result;
    char buf[15] = "destination";
    char p[200] = " source";

    result = ft_strlcat(buf, p, sizeof(buf));
    printf("%d\n", result);
    while (i < 18)
    {
        write(1, &buf[i], 1);
        i++;
    }
    return (0);
}
*/
