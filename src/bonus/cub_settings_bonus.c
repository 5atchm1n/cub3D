/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:24:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/05 03:22:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cub_set_bonus_paths(char *line, t_objects *objs)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'F' && *(line + 1) == 'L')
		objs->bpath[0] = cub_set_path(line, "FL");
	if (*line && *line == 'C' && *(line + 1) == 'E')
		objs->bpath[1] = cub_set_path(line, "CE");
	if (*line && *line == 'W' && *(line + 1) == '1')
		objs->bpath[2] = cub_set_path(line, "W1");
	if (*line && *line == 'W' && *(line + 1) == '2')
		objs->bpath[3] = cub_set_path(line, "W2");
	if (*line && *line == 'S' && *(line + 1) == 'K')
		objs->skypath = cub_set_path(line, "SK");
}

void		cub_bonus_textures(char *line, t_cub *game, t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && cub_isbonus(*line, *(line + 1)) == 1)
		error->bonus += 1;
	cub_set_bonus_paths(line, &game->world.objs);
}
