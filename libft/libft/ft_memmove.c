/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:33:50 by sshakya           #+#    #+#             */
/*   Updated: 2020/11/28 02:28:16 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		s = (unsigned char *)src;
		d = (unsigned char *)dest;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s = (unsigned char *)src + (n - 1);
		d = (unsigned char *)dest + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
