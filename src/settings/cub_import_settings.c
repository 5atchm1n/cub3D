/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_import_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:57:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/03 04:40:52 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_size(char *line, int *size_x)
{
	int			n;

	n = ft_strlen(line);
	if (n > *size_x)
		*size_x = n;
}

static void		cub_set_map_textures(char *line, t_cub *game, int *i,
		t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == '1')
	{
		cub_set_size(line, &game->world.info.msize.x);
		game->world.info.msize.y = game->world.info.msize.y + 1;
		error->map = 1;
	}
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		cub_set_texture_paths(line, &game->world.objs, i);
		if (ft_isspace(*(line + 1)))
			error->sprite += 1;
		else
			error->texture += 1;
	}
}

static void		cub_set_params(char *line, t_cub *game, t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == 'R')
	{
		cub_set_res(line, &game->mlx.res);
		error->res += 1;
	}
	if (*line == 'F')
	{
		cub_set_rgb(line, &game->world.info.floor);
		error->floor += 1;
	}
	if (*line == 'C')
	{
		cub_set_rgb(line, &game->world.info.ceiling);
		error->ceiling += 1;
	}
}

static void		cub_sanity_check(t_error *error)
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
	}
}

void			cub_import_settings(char *map_path, t_cub *game, t_error *error)
{
	int			fd;
	int			i;
	char		*line;

	fd = open(map_path, O_RDONLY);
	i = 0;
	while ((cub_get_line(&line, fd) > 0))
	{
		cub_set_params(line, game, error);
		cub_set_map_textures(line, game, &i, error);
		cub_sanity_check(error);
		free(line);
	}
	free(line);
	close(fd);
}
