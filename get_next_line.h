/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmushroo <lmushroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:46:08 by lmushroo          #+#    #+#             */
/*   Updated: 2021/01/01 00:10:33 by lmushroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char			*check_end_of_line(char **end_of_line, char **line);
int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);

#endif
