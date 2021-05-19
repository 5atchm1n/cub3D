/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:58:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 18:46:26 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_reset(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_size(char const *str, char c)
{
	size_t	size;
	int		end;

	size = 0;
	end = 1;
	if (!str)
		return (size);
	while (*str != '\0')
	{
		if (*str != c && end)
			size++;
		end = *str == c;
		str++;
	}
	return (size);
}

static char	*ft_set_string(char const *str, size_t len)
{
	size_t	i;
	char	*ret;

	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

static char	**ft_do_split(char c, char *str, char **tab, size_t size)
{
	size_t	len;
	size_t	n;

	n = 0;
	while (n < size)
	{
		len = 0;
		while (*str && *str == c)
			str++;
		while (*str && *str != c)
		{
			len++;
			str++;
		}
		tab[n] = ft_set_string((str - len), len);
		if (tab[n] == NULL)
			return (ft_reset(tab, n));
		n++;
	}
	tab[size] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	size_t	size;

	size = ft_size(str, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_do_split(c, (char *)str, tab, size);
	return (tab);
}
