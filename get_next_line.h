/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:29 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/11 17:45:42 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_gnljoin(char *s1, char *s2, int size);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src, int size);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
