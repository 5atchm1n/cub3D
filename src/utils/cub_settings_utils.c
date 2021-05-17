/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:45:35 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 18:48:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*cub_set_path(char *line, char *dir)
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
