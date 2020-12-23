/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmushroo <lmushroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:00:17 by lmushroo          #+#    #+#             */
/*   Updated: 2020/12/24 01:04:13 by lmushroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int l;

	l = 0;
	while (src[l] != '\0')
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

static char		*ft_clear(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

static char		*ft_newline(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char *)malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

static char		*check_end_of_line(char *end_of_line, char **line)
{
	char		*pointer_slash_n;

	pointer_slash_n = NULL;
	if (*end_of_line != 0)
		if((pointer_slash_n = ft_strchr(end_of_line, '\n')))
		{
			*pointer_slash_n = '\0';
			if ((*line = ft_strdup(end_of_line)) == NULL) //Does it here need checking for malloc?
				return (NULL);
			pointer_slash_n++;
			ft_strcpy(end_of_line, pointer_slash_n);
		}
		else
		{
			if ((*line = ft_strdup(end_of_line)) == NULL) //Does it here need checking for malloc?
				return (NULL);
			ft_clear(end_of_line);
		}
	else
		*line = ft_newline(1);
	return (pointer_slash_n);
}

int		get_next_line(int fd, char **line)
{
	static char		*end_of_line;
	char			buf[BUFFER_SIZE + 1];
	int				for_read;
	char			*pointer_slash_n;
	char			*str;

	pointer_slash_n = check_end_of_line(end_of_line, line);
	while (!pointer_slash_n && (for_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[for_read] = '\0';
		if ((pointer_slash_n = ft_strchr(buf, '\n')))
		{
			*pointer_slash_n = '\0';
			pointer_slash_n++;
			end_of_line = ft_strdup(pointer_slash_n);
		}
		str = *line;
		*line = ft_strjoin(*line, buf);
		free(str);
	}
	if (for_read || ft_strlen(end_of_line) || ft_strlen(*line))
		return (1);
	else
		return (0);
}

// int		main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("file.txt", O_RDONLY);
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// 	return (0);
// }
