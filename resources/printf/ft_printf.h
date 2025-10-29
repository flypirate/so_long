/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:02:01 by albegar2          #+#    #+#             */
/*   Updated: 2025/05/14 13:08:12 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H  //inclusion guard
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

size_t	ft_strlen(const char *s);
int		print_string(char *string_value);
int		print_pointer(void *pointer_value);
int		print_int(int int_value);
int		print_hex(unsigned int hex_value, char mayus);
int		print_char(char char_value);
int		print_unsigned(unsigned int n);
int		ft_printf(char const *argument, ...);
int		print_percent(char percent);

#endif