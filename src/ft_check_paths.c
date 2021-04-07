/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:43:40 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 20:56:52 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	ft_check_extension(char *path)
{
	len = ft_strlen(path);
	if (len < 4)
		return (-1);
	if (ft_isspace(path[len]))
		return (-1);
	if (path[len] != 'm')
		return (-1);
	if (path[len - 1] != 'p')
		return (-1);
	if (path[len - 2] != 'x')
		return (-1);
	if (path[len - 3] != '.')
		return (-1);
}

void		ft_check_paths(t_world *world)
{
	int		i;

	i = 0;
	while (i < TEXTURES)
	{
		ft_check_extension(world->tpath[i]);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		ft_check_extension(world->objpath[i]);
		i++;
	}
}

