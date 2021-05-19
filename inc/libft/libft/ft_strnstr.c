/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:40:34 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:32:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (*s1 && i < len)
	{
		j = 0;
		while (*(s2 + j) != '\0' && *(s2 + j) == *(s1 + j))
		{
			if (i + j >= len)
				return (NULL);
			j++;
		}
		if (*(s2 + j) == '\0')
			return ((char *)s1);
		s1++;
		i++;
	}
	return (NULL);
}
