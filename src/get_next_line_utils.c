/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:38:32 by edolgun           #+#    #+#             */
/*   Updated: 2023/01/14 00:23:25 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = 0;
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*copia;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (0);
	copia = malloc(sizeof(char) * (len + 1));
	if (!copia)
		return (0);
	while (s[start] && start < ((unsigned int)ft_strlen(s)) && i < len)
	{
		copia[i] = s[start];
		i++;
		start++;
	}
	copia[i] = '\0';
	return (copia);
}
