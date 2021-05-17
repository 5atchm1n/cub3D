/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:29:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_check_size(char *line, int size_x, int size_y)
{
	int			num;

	num = 0;
	if (line && *line == '"')
		line++;
	while (ft_isdigit(*line) && !ft_isspace(*line))
	{
		num = num * 10 + *line - 48;
		line++;
	}
	if (num != size_x)
		return (0);
	line++;
	num = 0;
	while (ft_isdigit(*line) && !ft_isspace(*line))
	{
		num = num * 10 + *line - 48;
		line++;
	}
	if (num != size_y)
		return (0);
	return (1);
}

static void		cub_check_header(char *line, int line_number, t_error *error,
		int bonus)
{
	if (line_number == 0 && ft_strcmp(line, "/* XPM */") == 0)
		error->id = INV_FILE;
	if (line_number == 3 && !bonus && cub_check_size(line, TEX_X, TEX_Y) == 0)
		error->id = INV_SIZE;
	if (line_number == 3 && bonus && cub_check_size(line, SKY_X, SKY_Y) == 0)
		error->id = INV_SIZE;
}

static void		cub_test_path(char **paths, t_error *error, int num, int bonus)
{
	int			i;
	char		*line;
	int			fd;
	int			ln;

	i = 0;
	while (i < num)
	{
		ln = 0;
		line = NULL;
		fd = open(paths[i], O_RDONLY);
		while ((cub_get_line(&line, fd) > 0))
		{
			cub_check_header(line, ln, error, bonus);
			free(line);
			ln++;
		}
		free(line);
		close(fd);
		if (error->id != 0)
			break ;
		i++;
	}
}

static void		cub_init_paths(t_objects *objs, t_error *error)
{
	objs->tpath = (char **)malloc(sizeof(char *) * TEXTURES);
	if (objs->tpath == NULL)
		error->id = MEM_FAIL;
	objs->spath = (char **)malloc(sizeof(char *) * SPRITES);
	if (objs->spath == NULL)
		error->id = MEM_FAIL;
	if (BONUS)
	{
		objs->bpath = (char **)malloc(sizeof(char *) * BONUS_OBJECTS);
		if (objs->bpath == NULL)
			error->id = MEM_FAIL;
	}
}

int				cub_settings(char *map_path, t_cub *game)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(t_error));
	error.id = 0;
	cub_init_paths(&game->world.objs, &error);
	if (error.id != 0)
		return (cub_error(error, game));
	cub_import_settings(map_path, game, &error);
	if (error.id != 0)
		return (cub_error(error, game));
	cub_test_path(game->world.objs.tpath, &error, TEXTURES, 0);
	if (error.id != 0)
		return (cub_error(error, game));
	cub_test_path(game->world.objs.spath, &error, SPRITES, 0);
	if (error.id != 0)
		return (cub_error(error, game));
	if (BONUS)
	{
		cub_test_path(game->world.objs.bpath, &error, BONUS_OBJECTS, 0);
		if (error.id != 0)
			return (cub_error(error, game));
	}
	return (0);
}
