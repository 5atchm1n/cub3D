/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:26:50 by sshakya           #+#    #+#             */
/*   Updated: 2020/11/30 19:51:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	l;
	char	*ret;

	ret = dest;
	l = ft_strlen(src);
	if (size == 0)
		return (l);
	size = size - 1;
	while (*src != '\0' && size > 0)
	{
		*ret = *src;
		ret++;
		src++;
		size--;
	}
	*ret = '\0';
	return (l);
}
