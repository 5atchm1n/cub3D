/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:45:35 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:13:44 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*cub_set_path(char *line, char *dir)
{
	char	*path;
	int		isdir;

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

void		cub_sanity_check(t_error *error)
{
	if (error->map == 1)
		if (error->texture != TEXTURES && error->res != 1 &&
				error->floor != 1 && error->ceiling != 1 &&
				error->sprite != SPRITES)
			error->id = MAP_NOEND;
	if (error->map == 1)
	{
		if (error->texture != TEXTURES)
			error->id = MI_FILES;
		if (error->sprite != SPRITES)
			error->id = MI_FILES;
		if (error->res != 1)
			error->id = MI_RES;
		if (error->floor != 1)
			error->id = MI_FLO;
		if (error->ceiling != 1)
			error->id = MI_CEI;
		if (BONUS && error->bonus != BONUS_OBJECTS + 1)
			error->id = MI_BONUS;
		if (error->texture == TEXTURES && error->tflags != 0xf)
			error->id = DUP_TEX;
	}
}
