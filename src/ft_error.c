/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:26:22 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 17:20:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_error_msg(int errnum, t_error error)
{
	char		*errmsg[ERRORS];

	errmsg[0] = "Invalid char in map - must contain only - NSEW - 0 1 2";
	errmsg[1] = "Map is open - check co-oridnates";
	errmsg[2] = "Path to xpm file is a directory";
	errmsg[3] = "Not a valid file";
	errmsg[4] = "Spaces at the end of the filepath";
	errmsg[5] = "Invalib .xpm file - check extension ";
	errmsg[6] = "Map must be at the end of map.cub";
	errmsg[7] = "Missing path to [Textures / Sprites]";
	errmsg[8] = "Missing Resolution";
	errmsg[9] = "Missing Floor colour";
	errmsg[10] = "Missing Ceiling colour";

	printf("Error\n");
	printf("%s", errmsg[errnum]);
	if (errnum == 1)
		printf(" x = %d\t y = %d", error.coords.x, error.coords.y);
	printf("\n");
}

void		ft_error(t_error error, t_cub *game)
{
	int		i;
	
	ft_error_msg(error.id - 1, error);
	i = 0;
	while (i < TEXTURES)
	{
		if (game->world.tpath[i])
			free(game->world.tpath[i]);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		if (game->world.objpath[i])
			free(game->world.objpath[i]);
		i++;
	}
	free(game->world.tpath);
	free(game->world.objpath);
	exit(0);
}
