/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_import_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:57:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:26:12 by sshakya          ###   ########.fr       */
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
	if (*line == '1' || *line == '0')
	{
		cub_set_size(line, &game->world.info.msize.x);
		game->world.info.msize.y = game->world.info.msize.y + 1;
		error->map = 1;
	}
	if (cub_isdir(*line) == 1)
	{
		cub_texture_path(line, &game->world.objs, error);
		cub_sprite_path(line, &game->world.objs, i);
		if (ft_isspace(*(line + 1)) == 1)
			error->sprite += 1;
		else if (cub_istex(*(line + 1)) == 1)
			error->texture += 1;
	}
}

static void		cub_set_params(char *line, t_cub *game, t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == 'R' && ft_isspace(*(line + 1)))
	{
		cub_set_res(line, &game->mlx.res, error);
		error->res += 1;
	}
	if (*line == 'F' && ft_isspace(*(line + 1)))
	{
		cub_set_rgb(line, &game->world.info.floor, error);
		error->floor += 1;
	}
	if (*line == 'C' && ft_isspace(*(line + 1)))
	{
		cub_set_rgb(line, &game->world.info.ceiling, error);
		error->ceiling += 1;
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
		if (BONUS)
			cub_bonus_textures(line, game, error);
		free(line);
	}
	free(line);
	close(fd);
}
