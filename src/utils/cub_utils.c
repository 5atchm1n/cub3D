/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:47:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:01:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	cub_issprite(char c)
{
	if (c == '2' || c == '3' || c == '4')
		return (1);
	return (0);
}

int	cub_istex(char c)
{
	if (c == 'O' || c == 'A' || c == 'E')
		return (1);
	return (0);
}

int	cub_isbonus(char c1, char c2)
{
	if (c1 == 'F' && c2 == 'L')
		return (1);
	if (c1 == 'C' && c2 == 'E')
		return (1);
	if (c1 == 'S' && c2 == 'K')
		return (1);
	if (c1 == 'W' && c2 == '1')
		return (1);
	if (c1 == 'W' && c2 == '2')
		return (1);
	return (0);
}

void	cub_error_set(t_error *error, t_errn id)
{
	error->id = id;
}
