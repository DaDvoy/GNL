/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmushroo <lmushroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:00:17 by lmushroo          #+#    #+#             */
/*   Updated: 2021/01/01 00:10:29 by lmushroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	l;

	l = 0;
	while (src[l] != '\0')
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

char	*check_end_of_line(char **end_of_line, char **line)
{
	char	*pointer_slash_n;

	pointer_slash_n = NULL;
	if (*end_of_line)
		if ((pointer_slash_n = ft_strchr(*end_of_line, '\n')))
		{
			*pointer_slash_n = '\0';
			if (!(*line = ft_strdup(*end_of_line)))
				return (NULL);
			ft_strcpy(*end_of_line, ++pointer_slash_n);
		}
		else
		{
			if (!(*line = ft_strdup(*end_of_line)))
				return (NULL);
			free(*end_of_line);
			*end_of_line = 0;
		}
	else
		*line = ft_strdup("");
	return (pointer_slash_n);
}

int		get_next_line(int fd, char **line)
{
	static char		*end_of_line = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				for_read;
	char			*pointer_slash_n;
	char			*str;

	if ((read(fd, buf, 0) == -1) || fd < 0 || BUFFER_SIZE <= 0
	|| line == NULL || (end_of_line == NULL &&
	(end_of_line = ft_strdup("")) == NULL))
		return (-1);
	pointer_slash_n = check_end_of_line(&end_of_line, line);
	while (!pointer_slash_n && (for_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[for_read] = '\0';
		if ((pointer_slash_n = ft_strchr(buf, '\n')))
		{
			*pointer_slash_n = '\0';
			if (!(end_of_line = ft_strdup(++pointer_slash_n)))
				return (-1);
		}
		str = *line;
		*line = ft_strjoin(*line, buf);
		free(str);
	}
	return ((pointer_slash_n || for_read) ? 1 : 0);
}
