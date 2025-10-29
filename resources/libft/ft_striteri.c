/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:54:00 by albertogm         #+#    #+#             */
/*   Updated: 2025/04/29 18:11:10 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	f(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z' && i % 2 == 1)
	{
		*c = (*c - 32);
	}
}
*/
/*
int main(void)
{
	char string[] = "hola bebés";
	int i = 0;
	ft_striteri(string, f);

	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
	return (0);
}
	*/
