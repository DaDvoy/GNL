/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmushroo <lmushroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:54:55 by lmushroo          #+#    #+#             */
/*   Updated: 2020/12/07 23:58:01 by lmushroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	int		y;
	char	sym;

	y = 0;
	sym = (char)c;
	while (s[y] != '\0')
	{
		if (s[y] == sym)
			return ((char *)(s + y));
		y++;
	}
	if (sym == '\0')
		return (char *)(s + y);
	return (NULL);
}


size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	y;

	y = 0;
	if (src == NULL || dst == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[y] != '\0' && y < (dstsize - 1))
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (ft_strlen(src));
}

size_t		ft_strlen(const char *str)
{
	int		bye;

	bye = 0;
	while (str[bye] != '\0')
	{
		bye++;
	}
	return (bye);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	ii;
	char	*str;

	i = -1;
	ii = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (++i < len_s1)
	{
		str[i] = s1[i];
	}
	while (i <= (len_s1 + len_s2))
	{
		str[i] = s2[ii];
		i++;
		ii++;
	}
	return (str);
}

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = (char *)malloc((len) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len);
	return (str);
}
