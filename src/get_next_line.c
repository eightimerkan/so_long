/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:38:34 by edolgun           #+#    #+#             */
/*   Updated: 2023/01/13 21:38:34 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*readbuf(int fd, char *line)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (r > 0 && !ft_strchr(buffer, '\n'))
	{
		r = read (fd, buffer, 1);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (r > 0)
		{
			buffer[r] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*line2;

	line2 = NULL;
	if (fd < 0)
		return (NULL);
	line = readbuf (fd, line2);
	return (line);
}
