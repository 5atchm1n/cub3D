/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:57:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 00:49:58 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_set_size(char *line, int *size_x)
{
	int			n;

	n = ft_strlen(line);
	if (n > *size_x)
		*size_x = n;
}

static void		ft_set_map_textures(char *line, t_cub *game, int *i,
		t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == '1')
	{
		ft_set_size(line, &game->world.msize.x);
		game->world.msize.y = game->world.msize.y + 1;
		error->map = 1;
	}
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		ft_set_texture_paths(line, &game->world, i);
		error->texture += 1;
	}
}

static void		ft_set_params(char *line, t_cub *game, t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == 'R')
	{
		ft_set_res(line, &game->mlx.res);
		error->res += 1;
	}
	if (*line == 'F')
	{
		ft_set_rgb(line, &game->world.floor);
		error->floor += 1;
	}
	if (*line == 'C')
	{
		ft_set_rgb(line, &game->world.ceiling);
		error->ceiling += 1;
	}
}

static void		ft_sanity_check(t_error *error)
{
	if (error->map == 1)
		if (error->texture != TEXTURES + SPRITES && error->res != 1 &&
				error->floor != 1 && error->ceiling != 1)
			error->id = MAP_NOEND;
	if (error->map == 1)
	{
		if (error->texture != TEXTURES + SPRITES)
			error->id = MI_FILES;
		if (error->res != 1)
			error->id = MI_RES;
		if (error->floor != 1)
			error->id = MI_FLO;
		if (error->ceiling != 1)
			error->id = MI_CEI;
	}
}

void			ft_import_settings(char *map_path, t_cub *game, t_error *error)
{
	int			fd;
	int			i;
	char		*line;

	fd = open(map_path, O_RDONLY);
	i = 0;
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_set_params(line, game, error);
		ft_set_map_textures(line, game, &i, error);
		ft_sanity_check(error);
		free(line);
	}
	free(line);
	close(fd);
}
