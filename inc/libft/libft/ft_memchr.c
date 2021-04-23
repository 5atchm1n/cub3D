/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:45:42 by sshakya           #+#    #+#             */
/*   Updated: 2020/11/28 02:51:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*new_str;
	size_t			i;

	new_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*new_str == (unsigned char)c)
			return (new_str);
		new_str++;
		i++;
	}
	return (NULL);
}
