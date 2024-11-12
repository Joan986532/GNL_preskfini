/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:01:23 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/11 18:31:31 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == (unsigned char)c || s[i] == '\0')
			return (&s[i + 1]);
		i++;
	}
	if (s[i] == '\0')
		return (&s[i]);
	return (0);
}

char	*ft_strcat(char *dest, char *src, int size)
{
	int	dest_len;
	int	i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[i] != '\0' && i < size)
	{
		dest[dest_len + i] = src[i];
		if (dest[dest_len + i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;	
	size_t	limit;
	size_t	i;

	i = 0;
	limit = -1;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb >= limit / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_gnljoin(char *s1, char *s2, int size)
{
	char	*sentence;
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	sentence = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!sentence)
		return (0);
	while (s1[i] != '\0')
	{
		sentence[i] = s1[i];
		i++;
	}
	sentence[i] = '\0';
	sentence = ft_strcat(sentence, s2, size);
	free(s1);
	return (sentence);
}
