/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:36:28 by albegar2          #+#    #+#             */
/*   Updated: 2025/08/13 14:39:17 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//BUFFER_SIZE + 1 to account for null 

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*nextline;
	static char	*stash;

	nextline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	nextline = reading_loop(&stash, buffer, nextline, fd);
	free(buffer);
	return (nextline);
}

char	*reading_loop(char **stash, char *buffer, char *nextline, int fd)
{
	int		bytes_read;
	char	*temp;

	while (1)
	{
		if (*stash && custom_ft_strchr(*stash, '\n') != NULL)
			return (process(nextline, stash));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
		{
			free(*stash);
			return (*stash = NULL, NULL);
		}
		free(*stash);
		*stash = temp;
		if (stash && custom_ft_strchr(*stash, '\n') != NULL)
			return (process(nextline, stash));
	}
	if (bytes_read <= 0)
		nextline = eof_or_error(&nextline, stash, bytes_read);
	return (nextline);
}

size_t	newlinepos(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		else
			i++;
	}
	return (i);
}

char	*process(char *nextline, char **stash)
{
	char	*newlinepos;
	char	*temp;
	size_t	newline_len;

	newlinepos = custom_ft_strchr(*stash, '\n');
	if (newlinepos)
	{
		newline_len = newlinepos - *stash;
		nextline = ft_substr(*stash, 0, newline_len + 1);
		temp = ft_strdup(newlinepos + 1);
		if (!temp)
			return (free(*stash), *stash = NULL, NULL);
		free(*stash);
		*stash = temp;
	}
	else
	{
		nextline = ft_substr(*stash, 0, custom_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	return (nextline);
}

//controls cases of bytes_read = 0 and bytes _read = negative
char	*eof_or_error(char **nextline, char **stash, int bytes_read)
{
	char	*temp;

	if (bytes_read == 0 && *stash && custom_strlen(*stash) > 0)
	{
		if (custom_ft_strchr(*stash, '\n') != NULL)
		{
			*nextline = ft_substr(*stash, 0, newlinepos(*stash));
			temp = ft_strdup(custom_ft_strchr(*stash, '\n'));
			free (*stash);
			*stash = temp;
		}
		else
			*nextline = ft_substr(*stash, 0, custom_strlen(*stash));
		if (!*nextline)
			return (free(*stash), *stash = NULL, NULL);
		free(*stash);
		*stash = NULL;
		return (*nextline);
	}
	return (free(*stash), *stash = NULL, NULL);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 1)
	{
		write(2, "Error at opening file", 21);
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
*/