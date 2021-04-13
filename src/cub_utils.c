/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:47:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/13 04:21:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strcmp(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		i;

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

int			ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

double		ft_fmax(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double		ft_fmin(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int			cub_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
