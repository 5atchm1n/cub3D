/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:26:22 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 01:09:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_error_msg(int errnum, t_error error)
{
	char		*errmsg[ERRORS];

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
	errmsg[12] = "\033[31m\t MLX fail \033[36m INIT";
	errmsg[12] = "\033[31m\t MLX fail \033[36m can't read XPM file";
	printf("\033[31mError\033[0m\n ");
	printf("%s", errmsg[errnum]);
	if (errnum == 1)
		printf("\033[0m [x = %d\t] [y = %d]", error.coords.x, error.coords.y);
	if (errnum == 11)
		printf("\033[0m - Must be %d by %d", TEX_X, TEX_Y);
	printf("\n");
}

static int		ft_free_state_0(t_cub *game)
{
	int			i;

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

void			ft_error(t_error error, t_cub *game, int state)
{
	ft_error_msg(error.id - 1, error);
	if (state == 0)
		ft_free_state_0(game);
}
