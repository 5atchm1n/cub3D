/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 03:37:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:51:54 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	if (n != 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}
