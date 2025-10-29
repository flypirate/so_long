/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:36:34 by albegar2          #+#    #+#             */
/*   Updated: 2025/06/17 16:41:14 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	custom_strlen(char *string);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*reading_loop(char	**stash, char *buffer, char *nextline, int fd);
size_t	newlinepos(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*process(char *nextline, char **stash);
char	*eof_or_error(char *nextline, char **stash, int bytes_read);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
