/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:26:22 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 18:43:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_errmsg(char **errmsg)
{
	errmsg[0] = "\033[36m\tInvalid char in map\033[0m";
	errmsg[1] = "\033[36m\tMap is open - check co-oridnates\033[0m";
	errmsg[2] = "\033[36m\tPath to xpm file is a directory\033[0m";
	errmsg[3] = "\033[36m\tNot a valid XPM file\033[0m";
	errmsg[4] = "\033[36m\tSpaces at the end of the filepath\033[0m";
	errmsg[5] = "\033[36m\tInvalib .xpm file - check extension\033[0m";
	errmsg[6] = "\033[36m\tMap must be at the end of map.cub\033[0m";
	errmsg[7] = "\033[36m\tMissing path to [Textures / Sprites]\033[0m";
	errmsg[8] = "\033[36m\tMissing or invalid Resolution\033[0m";
	errmsg[9] = "\033[36m\tMissing or invalid Floor colour\033[0m";
	errmsg[10] = "\033[36m\tMissing or invalid Ceiling colour\033[0m";
	errmsg[11] = "\033[36m\tXPM size is not valid\033[0m";
	errmsg[12] = "\033[31m\tsystem fail \033[36m MALLOC\033[0m";
	errmsg[13] = "\033[31m\tMLX fail \033[36m INIT\033[0m";
	errmsg[14] = "\033[31m\tMLX fail \033[36m can't read XPM file\033[0m";
	errmsg[15] = "\033[36m\tInvalid RGB R[0-255] G[0-255] B[0-255]\033[0m";
	errmsg[16] = "\033[36m\tMultiple start positions\033[0m";
	errmsg[17] = "\033[36m\tInvalid map file\033[0m";
	errmsg[18] = "\033[36m\tMust be in the format \033[0m[ --save ]";
	errmsg[19] = "\033[36m\tDuplicate texture \033[33m[NO/SO/EA/WE]\033[0m";
	errmsg[20] = "\033[36m\tBonus Map is not valid \033[0m";
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
		printf("\033[33m [x = %d] [y = %d]", error.coords.x, error.coords.y);
	if (errnum == 11)
		printf("\033[0m - Must be %d by %d", TEX_X, TEX_Y);
	printf("\n");
	return ;
}
/*
static void		cub_free_state_0(t_cub *game, int tex, int spr)
{
	int			i;

	i = 0;
	while (i < tex)
	{
		free(game->world.objs.tpath[i]);
		i++;
	}
	i = 0;
	while (i < spr)
	{
		free(game->world.objs.spath[i]);
		i++;
	}
	free(game->world.objs.tpath);
	free(game->world.objs.spath);
}

static void		cub_free_bonus(t_cub *game, int bonus)
{
	int			i;

	i = 0;
	while (i < bonus)
	{
		free(game->world.objs.bpath[i]);
		i++;
	}
	i = 0;
	free(game->world.objs.bpath);
	if (game->world.objs.skypath != NULL)
		free(game->world.objs.skypath);
}
*/
int				cub_error(t_error error, t_cub *game, int state)
{
	cub_error_msg(error.id, error);
	/*
	if (state == 0)
	{
		cub_free_state_0(game, TEXTURES, SPRITES);
		exit(0);
	}
	if (state == 1 && !BONUS)
	{
		cub_free_state_0(game, error.texture, error.sprite);
		exit(0);
	}
	if (BONUS && state == 1)
	{
		cub_free_state_0(game, error.texture, error.sprite);
		cub_free_bonus(game, error.bonus);
		exit(0);
	}
	*/
	if (state == 2 || state == 1|| state == 0)
		cub_quit(game);
	return (1);
}
