/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:41:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:31:47 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_free_utils(t_world *world)
{
	int		i;

	i = 0;
	while (i < WEAPONS * 2)
	{
		if (world->objs.weapons != NULL)
			free(world->objs.weapons[i]);
		i++;
	}
	free(world->objs.weapons);
	i = 0;
	while (i < BONUS_OBJECTS)
	{
		if (world->objs.bpath != NULL)
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
		printf("\033[31m \t\tGAME OVER\033[0m\n");
	if (kill == count && player.health >= 1)
		printf("\033[31m \t\tYOU WIN !\033[0m\n");
}

void	cub_quit_bonus(t_cub *game)
{
	if (game->mlx.on == 1)
	{
		mlx_mouse_show(game->mlx.win.mlx, game->mlx.win.win);
		cub_win(game->world.info, game->world.sprite, game->player);
	}
	cub_free_utils(&game->world);
}
