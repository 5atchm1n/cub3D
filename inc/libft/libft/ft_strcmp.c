/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:32:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:31:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	l1;
	int	l2;
	int	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	if (l1 != l2)
		return (0);
	while (i < l1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
