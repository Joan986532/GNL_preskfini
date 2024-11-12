/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnauroy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:09 by jnauroy           #+#    #+#             */
/*   Updated: 2024/11/12 15:10:20 by jnauroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//V2

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("theclash.txt", O_RDONLY);
/*	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);*/

	do
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	} while (line);
	close(fd);
}

