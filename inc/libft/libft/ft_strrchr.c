/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:32:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	unsigned char	ch;
	char			*s;

	i = ft_strlen(str);
	ch = (unsigned char)c;
	s = (char *)str;
	while (i != 0)
	{
		if (*(s + i) == ch)
			return (s + i);
		i--;
	}
	if (*s == ch)
		return (s);
	return (NULL);
}
