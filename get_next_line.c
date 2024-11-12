/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:34 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/12 15:12:01 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_string(char *buffer)
{
	char	*string;

	string = malloc(sizeof(char));
	if (!string)
		return (0);
	*string = '\0';
	if (!buffer)
		return (string);
	buffer = ft_strchr(buffer, '\n');
	string = ft_gnljoin(string, buffer, BUFFER_SIZE);
	if (!string)
	{
		free(buffer);
		return (0);
	}
	return (string);
}

char	*init_buffer(char *buffer)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (buffer)
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i + 1];
			j++;
			i++;
		}
		return (buffer);
	}
	if (!buffer)
	{
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
	}
	return (buffer);
}

int	check_for_bsn(char *str, int size)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (0);
		i++;
	}
	if (size == -1)
		return (1);
	if (size < BUFFER_SIZE && str[i] == '\0')
		return (0);
	return (1);
}

char	*ft_free(char *string, char *buffer)
{
	free(string);
	free(buffer);
	buffer = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*string;
	int			size;

	if(read(fd, 0, 0) == -1)
		return (NULL);
	string = init_string(buffer);
	buffer = init_buffer(buffer);
	if (!string || !buffer)
		return (0);
	size = -1;
	while (check_for_bsn(string, size))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (ft_free(string, buffer));
		string = ft_gnljoin(string, buffer, size);
	}
	if (*buffer == '\0')
		free(buffer);
	return (string);
}
