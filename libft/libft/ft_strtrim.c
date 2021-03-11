/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 03:28:58 by sshakya           #+#    #+#             */
/*   Updated: 2020/11/27 17:35:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_in_set(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_start(const char *str, const char *set)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (ft_in_set(str[i], set))
			start++;
		i++;
		if (!(ft_in_set(str[i], set)))
			return (start);
	}
	return (0);
}

static	size_t	ft_end(const char *str, const char *set, size_t len)
{
	size_t	end;

	end = 0;
	while (len > 0)
	{
		if (ft_in_set(str[len], set))
			end++;
		len--;
		if (!(ft_in_set(str[len], set)))
			return (end);
	}
	return (0);
}

char			*ft_strtrim(char const *str, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*ret;

	len = ft_strlen(str);
	len = len - (ft_start(str, set) + ft_end(str, set, len));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = ft_start(str, set);
	j = 0;
	while (j < len)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
