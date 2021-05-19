/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 19:17:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_find(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_dup(const char *src, const char *srcfree)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (gnl_len(src) + 1));
	if (dup == NULL)
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

static char	*gnl_do_join(char *s1, char *s2, char *str)
{
	size_t	i;
	size_t	j;

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

char	*gnl_join(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	len = gnl_len(s1) + gnl_len(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = gnl_do_join(s1, s2, str);
	return (str);
}

char	*gnl_sub(const char *s, unsigned int start, size_t len, int n)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (gnl_len(s) < start + len)
		len = gnl_len(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
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
