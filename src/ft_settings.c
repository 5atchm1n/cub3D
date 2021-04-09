/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 06:15:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_check_size(char *line)
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
	if (num != TEX_X)
		return (0);
	line++;
	num = 0;
	while (ft_isdigit(*line) && !ft_isspace(*line))
	{
		num = num * 10 + *line - 48;
		line++;
	}
	if (num != TEX_Y)
		return (0);
	return (1);
}

static void		ft_check_header(char *line, int line_number, t_error *error)
{
	if (line_number == 0 && ft_strcmp(line, "/* XPM */") == 0)
		error->id = INV_FILE;
	if (line_number == 3 && ft_check_size(line) == 0)
		error->id = INV_SIZE;
}

static void		ft_test_path(char **paths, t_error *error, int num)
{
	int			i;
	char		*line;
	int			fd;
	int			ln;

	i = 0;
	while (i < num)
	{
		ln = 0;
		fd = open(paths[i], O_RDONLY);
		while ((ft_get_line(&line, fd) > 0))
		{
			ft_check_header(line, ln, error);
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

int				ft_settings(char *map_path, t_cub *game)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(t_error));
	game->world.tpath = (char **)malloc(sizeof(char *) * TEXTURES);
	if (game->world.tpath == NULL)
		error.id = M_FAIL;
	game->world.objpath = (char **)malloc(sizeof(char *) * SPRITES);
	if (game->world.objpath == NULL)
		error.id = M_FAIL;
	if (error.id != 0)
		ft_error(error, game, 0);
	ft_import_settings(map_path, game, &error);
	if (error.id != 0)
		ft_error(error, game, 0);
	ft_test_path(game->world.tpath, &error, TEXTURES);
	if (error.id != 0)
		ft_error(error, game, 0);
	ft_test_path(game->world.objpath, &error, SPRITES);
	if (error.id != 0)
		ft_error(error, game, 0);
	return (0);
}
