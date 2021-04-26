/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:26:22 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/26 15:07:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_errmsg(char **errmsg)
{
	errmsg[0] = "\033[36m\tInvalid char in map";
	errmsg[1] = "\033[36m\tMap is open - check co-oridnates";
	errmsg[2] = "\033[36m\tPath to xpm file is a directory";
	errmsg[3] = "\033[36m\tNot a valid XPM file";
	errmsg[4] = "\033[36m\tSpaces at the end of the filepath";
	errmsg[5] = "\033[36m\tInvalib .xpm file - check extension ";
	errmsg[6] = "\033[36m\tMap must be at the end of map.cub";
	errmsg[7] = "\033[36m\tMissing path to [Textures / Sprites]";
	errmsg[8] = "\033[36m\tMissing Resolution";
	errmsg[9] = "\033[36m\tMissing Floor colour";
	errmsg[10] = "\033[36m\tMissing Ceiling colour";
	errmsg[11] = "\033[36m\tXPM size is not valid";
	errmsg[12] = "\033[31m\t system fail \033[36m MALLOC";
	errmsg[13] = "\033[31m\t MLX fail \033[36m INIT";
	errmsg[14] = "\033[31m\t MLX fail \033[36m can't read XPM file";
	errmsg[15] = "\033[36m Invalid RGB input [0 - 255]";
	errmsg[16] = "\033[36m Multiple start positions";
	errmsg[17] = "\033[36m Invalid map file";
	errmsg[18] = "\033[36m Must be in the format \033[0m[ --save ]";
}

void			cub_error_msg(t_errn id, t_error error)
{
	char		*errmsg[ERRORS];
	int			errnum;

	errnum = id - 1;
	cub_set_errmsg(errmsg);
	printf("\033[31mError\033[0m\n ");
	printf("%s", errmsg[errnum]);
	if (errnum == 1 || errnum == 0)
		printf("\033[0m [x = %d] [y = %d]", error.coords.x, error.coords.y);
	if (errnum == 11)
		printf("\033[0m - Must be %d by %d", TEX_X, TEX_Y);
	printf("\n");
}

static int		cub_free_state_0(t_cub *game, int tex, int spr)
{
	int			i;

	i = 0;
	while (i < tex)
	{
		if (game->world.tpath[i])
			free(game->world.tpath[i]);
		i++;
	}
	i = 0;
	while (i < spr)
	{
		if (game->world.objpath[i])
			free(game->world.objpath[i]);
		i++;
	}
	free(game->world.tpath);
	free(game->world.objpath);
	exit(0);
}

void			cub_error_set(t_error *error, t_errn id)
{
	error->id = id;
}

void			cub_error(t_error error, t_cub *game, int state)
{
	cub_error_msg(error.id, error);
	if (state == 0)
		cub_free_state_0(game, TEXTURES, SPRITES);
	if (state == 1)
		cub_free_state_0(game, error.texture, error.sprite);
	if (state == 2)
		cub_quit(game);
	exit(0);
}
