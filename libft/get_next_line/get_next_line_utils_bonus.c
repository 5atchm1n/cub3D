/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:38 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/24 07:08:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		gnl_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int			gnl_find(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*gnl_dup(const char *src, const char *srcfree)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (!(dup = malloc(sizeof(char) * (gnl_len(src) + 1))))
		return (NULL);
	while (src && src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	if (srcfree)
		free((char *)srcfree);
	return (dup);
}

char		*gnl_join(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = gnl_len(s1) + gnl_len(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char		*gnl_sub(const char *s, unsigned int start, size_t len, int n)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (gnl_len(s) < start + len)
		len = gnl_len(s) - start;
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0 && *(s + start) != '\0')
	{
		sub[i] = s[i + start];
		i++;
		len--;
	}
	sub[i] = '\0';
	if (n == 1)
		free((char *)s);
	return (sub);
}
