/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:41:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:45:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_free_utils(t_world *world)
{
	int		i;

	i = 0;
	while (i < WEAPONS * 2)
	{
		free(world->objs.weapons[i]);
		i++;
	}
	free(world->objs.weapons);
	i = 0;
	while (i < BONUS_OBJECTS)
	{
		free(world->objs.bpath[i]);
		i++;
	}
	free(world->objs.bpath);
	free(world->objs.skypath);
	free(world->objs.sky);
	free(world->objs.skybox);
	free(world->objs.ground);
}

static void	cub_win(t_info info, t_sprite *sprite, t_player player)
{
	int		i;
	int		count;
	int		kill;

	kill = 0;
	count = 0;
	i = 0;
	while (i < info.scount)
	{
		if (sprite[i].id == 2)
			count++;
		i++;
	}
	i = 0;
	while (i < info.scount)
	{
		if (sprite[i].id == 2 && sprite[i].state & S_KILL)
			kill++;
		i++;
	}
	if (player.health < 1)
		printf("GAME OVER\n");
	if (kill == count && player.health >= 1)
		printf("YOU WIN !\n");
}

void		cub_quit_bonus(t_cub *game)
{
	mlx_mouse_show(game->mlx.win.mlx, game->mlx.win.win);
	cub_win(game->world.info, game->world.sprite, game->player);
	cub_free_utils(&game->world);
}
