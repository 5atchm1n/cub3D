/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:11:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:27:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*ft_set_path(char *line, char *dir)
{
	char		*path;
	int			isdir;

	path = NULL;
	isdir = 0;
	if (*line && *line == dir[0])
		isdir++;
	line++;
	if (*line && *line == dir[1])
	{
		isdir++;
		line++;
	}
	while (*line && ft_isspace(*line))
		line++;
	if (isdir == 2)
		path = ft_strdup(line);
	return (path);
}

static char		*ft_set_sprite_path(char *line)
{
	char		*path;
	int			issprite;

	issprite = 0;
	path = NULL;
	if (*line == 'S')
		line++;
	while (ft_isspace(*line) == 1)
	{
		issprite = 1;
		line++;
	}
	if (issprite)
		path = ft_strdup(line);
	return (path);
}

void			ft_set_texture_paths(char *line, t_world *world, int *i)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'N')
		world->tpath[0] = ft_set_path(line, "NO");
	if (*line && *line == 'S' && *(line + 1) == 'O')
		world->tpath[1] = ft_set_path(line, "SO");
	if (*line && *line == 'E')
		world->tpath[2] = ft_set_path(line, "EA");
	if (*line && *line == 'W')
		world->tpath[3] = ft_set_path(line, "WE");
	if (*line && *line == 'S' && ft_isspace(*(line + 1)) && *i < SPRITES)
	{
		world->objpath[*i] = ft_set_sprite_path(line);
		*i = *i + 1;
	}
}
